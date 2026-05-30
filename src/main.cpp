

#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>
#include <string.h>

//Data Frame Struct
typedef struct __attribute__(packed))
{
  uint16_t sync_id;
  uint32_t packet_cnt
  float sensor_reading;
} TacticalPacket;

void on_data_recv(const uint8_t *mac_addr, const uint8_t *incoming_data, int len)
{
  if (len != sizeof(TacticalPacket))
  {
    return;
  }
  TacticalPacket incoming_packet:
  memcpy(&incoming_packet, incoming_data, sizeof(incoming_packet));

  Serial.print("Packet Received ID: ");
  Serial.println(incoming_packet.packet_seq);
}

void setup()
{
  //Open Serial bus Link //
  Serial.begin(230400);
  delay(200);

  //Station mode for control
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  //ESP-NOW Protocol init
  if(esp_now_init() != ESP_OK)
  {
    Serial.println ("Error Initialising ESP-NOW");
    return;
  }

  esp_now_register_recv_cn(esp_now_recv_cb_t(on_data_recv));

  Serial.println("System Configuration Complete. Radio Monitoring Active.");
}

void loop()
{
  //Execution placeholder
  delay(1000);
}
