#define SERIES_RESISTOR     1275    // Value of the series resistor in ohms.    
#define SENSOR_PIN          A0      // Analog pin which is connected to the sensor. 

// #define ZERO_VOLUME_RESISTANCE    1465.18    // Resistance value (in ohms) when no liquid is present.
// #define CALIBRATION_RESISTANCE    480.48    // Resistance value (in ohms) when liquid is at max line.
// #define CALIBRATION_VOLUME        8.00    // Volume (in any units) when liquid is at max line.
class ETapeSensor : public PollingComponent, public Sensor {

  private:
    esphome::sensor::Sensor* tEmpty;
    esphome::sensor::Sensor* tFull;
    esphome::sensor::Sensor* tUnits;
    esphome::binary_sensor::BinarySensor* tPump;
  
  public:
    // constructor
    
    ETapeSensor(esphome::sensor::Sensor* empty, esphome::sensor::Sensor* full, esphome::sensor::Sensor* units) : PollingComponent(15000) {
      tEmpty = empty;
      tFull = full;
      tUnits = units;
    };

    Sensor *etape_sensor = new Sensor();
    Sensor *voltage_sensor = new Sensor();
    Sensor *resistance_sensor = new Sensor();

    float get_setup_priority() const override { return esphome::setup_priority::DATA; }
    
    float readResistance(float voltage, int seriesResistance) {
      // Get ADC value.
      float resistance = voltage;
      // Convert ADC reading to resistance.
      resistance = (1023.0 / resistance) - 1.0;
      resistance = seriesResistance / resistance;
      return resistance;
    }

  float resistanceToVolume(float resistance, float zeroResistance, float calResistance, float calVolume) {
    if (resistance > zeroResistance || (zeroResistance - calResistance) == 0.0) {
      // Stop if the value is above the zero threshold, or no max resistance is set (would be divide by zero).
      return 0.0;
    }
    // Compute scale factor by mapping resistance to 0...1.0+ range relative to maxResistance value.
    float scale = (zeroResistance - resistance) / (zeroResistance - calResistance);
    // Scale maxVolume based on computed scale factor.
    return calVolume * scale;
  }

    void setup() override {
    }

    void update() override {
      float voltage = analogRead(SENSOR_PIN);
      float resistance = readResistance(voltage, SERIES_RESISTOR);
      float volume = resistanceToVolume(resistance, tEmpty->state, tFull->state, tUnits->state);
  
      voltage_sensor->publish_state(voltage);
      resistance_sensor->publish_state(resistance);
      etape_sensor->publish_state(volume);
    }
};
