/*
MIT License

Copyright (c) 2020 Atlas Scientific

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE
*/

#ifndef PH_GRAV_H
#define PH_GRAV_H

//#include "base_grav.h"
#include "EEPROM.h"

class Gravity_pH : public Gravity_Base{
	public:
	
		Gravity_pH(uint8_t pin);
		
		bool begin();
	
		virtual float read_voltage();
		float read_ph(float voltage_mV, float low, float mid, float high);
		//float read_ph(float low, float mid, float high);
		
		void cal_mid(float voltage_mV);
		void cal_mid();
		
		void cal_low(float voltage_mV);
		void cal_low();
		
		void cal_high(float voltage_mV);
		void cal_high();
	
		void cal_clear();
		
	private:

    uint8_t pin = A0;
        
		static const int volt_avg_len = 1000;
    static const uint8_t EEPROM_SIZE_CONST = 16;
		static const uint8_t magic_char = 0xAA;
        
    int16_t EEPROM_offset = 0;
		
		struct PH {
		  const uint8_t magic = magic_char;
		  float mid_cal = 1490.00; //1500;
		  float low_cal =  2030.00;// 1915.96;
		  float high_cal = 951.98; //975;
		};
		struct PH pH;
};

Gravity_pH::Gravity_pH(uint8_t pin){
	this->pin = pin;
    this->EEPROM_offset = (pin) * EEPROM_SIZE_CONST;
    //to lay the calibration parameters out in EEPROM we map their locations to the analog pin numbers
    //we assume a maximum size of EEPROM_SIZE_CONST for every struct we're saving
}

bool Gravity_pH::begin(){
    //#if defined(ESP8266) || defined(ESP32)
  //  EEPROM.begin(1024);
    //#endif 
	// if(EEPROM.read(this->EEPROM_offset) == magic_char){
	// 	EEPROM.get(this->EEPROM_offset,pH);
	// 	return true;
  //   }
  // this->pH.low_cal = low;
  // this->pH.mid_cal = mid;
  // this->pH.high_cal = high;

	return true;
}

float Gravity_pH::read_voltage() {
      float voltage_mV = 0;
      for (int i = 0; i < volt_avg_len; ++i) {
        voltage_mV += analogRead(this->pin) / 1023.0 * 3200.00;
      }
      voltage_mV /= volt_avg_len;
      return voltage_mV;
}

float Gravity_pH::read_ph(float voltage_mV, float low, float mid, float high) {
  if (voltage_mV > mid) { //high voltage = low ph
    return 7.0 - 3.0 / (low - mid) * (voltage_mV - mid);
  } else {
    return 7.0 - 3.0 / (mid - high) * (voltage_mV - mid);
  }
}

// float Gravity_pH::read_ph(float voltage, float low, float mid, float high) {
//   return(read_ph(voltage, low, mid, high));
// }

void Gravity_pH::cal_mid(float voltage_mV) {
  this->pH.mid_cal = voltage_mV;
  EEPROM.put(this->EEPROM_offset,pH);
  #if defined(ESP8266) || defined(ESP32)
    EEPROM.commit(); 
  #endif
}

void Gravity_pH::cal_mid() {
  cal_mid(read_voltage());
}

void Gravity_pH::cal_low(float voltage_mV) {
  this->pH.low_cal = voltage_mV;
  EEPROM.put(this->EEPROM_offset,pH);
  #if defined(ESP8266) || defined(ESP32)
    EEPROM.commit(); 
  #endif
}

void Gravity_pH::cal_low() {
  cal_low(read_voltage());
}

void Gravity_pH::cal_high(float voltage_mV) {
  this->pH.high_cal = voltage_mV;
  EEPROM.put(this->EEPROM_offset,pH);
  #if defined(ESP8266) || defined(ESP32)
    EEPROM.commit(); 
  #endif
}

void Gravity_pH::cal_high() {
  cal_high(read_voltage());
}

void Gravity_pH::cal_clear() {
  this->pH.mid_cal = 1500;
  this->pH.low_cal = 2030;
  this->pH.high_cal = 975;
  EEPROM.put(this->EEPROM_offset,pH);
  // 1420.136852394916911.2
  //return 7.0 - 3.0 / (this->pH.mid_cal - this->pH.high_cal) * (voltage_mV - this->pH.mid_cal);
  //return 7.0 - 3.0 / (2030 - 1500) * (2241.2 - 1500);
}


#endif