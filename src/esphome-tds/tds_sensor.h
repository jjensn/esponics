#include "GravityTDS.h"

GravityTDS gravityTds;

class TdsSensor : public PollingComponent, public Sensor {

  private:
    esphome::sensor::Sensor* sTemp;
  
  public:
    // constructor
    
    TdsSensor(esphome::sensor::Sensor* temp) : PollingComponent(15000) {
      sTemp = temp;
    };

    Sensor *tds_sensor = new Sensor();
    Sensor *voltage_sensor = new Sensor();
    float get_setup_priority() const override { return esphome::setup_priority::DATA; }
    

    void setup() override {
      
      gravityTds.setPin(A0);
      gravityTds.setAref(3.3);
      gravityTds.setAdcRange(1024);  //1024 for 10bit ADC;4096 for 12bit ADC
      gravityTds.begin();  //initialization
      
    }

    float ftoc(float temp) {
      return (temp - 32.0) / 1.8;
    }
    void update() override {
      
      //float ph_measurement = pH.read_ph();
      //ESP_LOGD("custom", "%.2f | %.2d | %.2f", ph_measurement, analogRead(A0), pH.read_voltage());
      //ESP_LOGD("custom", "%.2f | %.2f | %.2f", pH.pH.mid_cal, pH.pH.low_cal, pH.pH.high_cal);

      float nuteTemp = ftoc(sTemp->state);

      gravityTds.setTemperature(nuteTemp);
      
      gravityTds.update();  //sample and calculate 
      float tdsValue = gravityTds.getTdsValue();  // then get the value
      // ESP_LOGD("custom", "%.2f | %.2f", tdsValue, nuteTemp);
      tds_sensor->publish_state(tdsValue);
      voltage_sensor->publish_state(analogRead(A0));
    }
};