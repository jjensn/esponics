 #include "ph_grav.h"

Gravity_pH pH = Gravity_pH(17);

 class AtlasScientificPHSensor : public PollingComponent, public Sensor {
  private:
    esphome::sensor::Sensor* tLow;
    esphome::sensor::Sensor* tMid;
    esphome::sensor::Sensor* tHigh;
  public:
    // constructor
    
    AtlasScientificPHSensor(esphome::sensor::Sensor* low, esphome::sensor::Sensor* mid, esphome::sensor::Sensor* high) : PollingComponent(15000) {
      tLow = low;
      tMid = mid;
      tHigh = high;
    };

    Sensor *ph_sensor = new Sensor();
    Sensor *voltage_sensor = new Sensor();
    Sensor *resistance_sensor = new Sensor();

    float get_setup_priority() const override { return esphome::setup_priority::DATA; }
    

    void setup() override {

    }
    void update() override {
      float resistance = pH.read_voltage();
      float ph_measurement = pH.read_ph(resistance, tLow->state, tMid->state, tHigh->state);
      
      //ESP_LOGD("custom", "%.2f | %.2d | %.2f", ph_measurement, analogRead(A0), pH.read_voltage());
      //ESP_LOGD("custom", "%.2f | %.2f | %.2f", pH.pH.mid_cal, pH.pH.low_cal, pH.pH.high_cal);

      ph_sensor->publish_state(ph_measurement);
      voltage_sensor->publish_state(analogRead(A0));
      resistance_sensor->publish_state(resistance);
    }
};