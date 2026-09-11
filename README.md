# 🌤️ ESP8266 Weather Station & Blynk IoT (Lab 7)

โปรเจกต์สถานีวัดอากาศอัจฉริยะด้วย **ESP8266 (NodeMCU)** แสดงผลข้อมูลแบบ Real-time บน **Blynk 2.0 Web Dashboard** โดยรับค่าจากเซนเซอร์ 3 ชนิด เพื่อตรวจจับอุณหภูมิ ความชื้น ดัชนีความร้อน สถานะแสงกลางวัน/กลางคืน และสถานะฝนตก

---

## 📌 คุณสมบัติ (Features)

* 🌡️ **วัดอุณหภูมิและความชื้น:** อ่านค่าจากเซนเซอร์ DHT11
* 🤒 **คำนวณ Feel Like:** คำนวณค่าดัชนีความร้อน (Heat Index) โดยอัตโนมัติ
* ☀️ **ตรวจจับแสง (Day/Night):** ตรวจสอบสถานะกลางวัน/กลางคืนด้วย LDR Sensor
* 🌧️ **ตรวจจับน้ำฝน (Rain Status):** ตรวจจับสถานะฝนกำลังตก/ฝนไม่ตกด้วย Rain Sensor
* ⚡ **Real-time Updates:** ส่งข้อมูลสถานะดิจิทัลขึ้น Blynk Dashboard ทันทีแบบไม่ดีเลย์

---

## 🛠️ อุปกรณ์ที่ใช้ (Hardware Requirements)

1. **ESP8266** (NodeMCU V2/V3)
2. **DHT11** Temperature and Humidity Sensor
3. **LDR Sensor Module** (Light Dependent Resistor)
4. **Rain Sensor Module**
5. สายสายนพผ่อน (Jumper Wires) และ Breadboard

---

## 🔌 การต่อวงจร (Wiring Diagram)

| อุปกรณ์ (Component) | ขาเซนเซอร์ (Sensor Pin) | ขาบน ESP8266 (NodeMCU Pin) |
| :--- | :--- | :--- |
| **DHT11** | VCC <br> GND <br> DATA | 3V3 / 5V <br> GND <br> **D4** (GPIO2) |
| **LDR Module** | VCC <br> GND <br> DO (Digital Out) | 3V3 / 5V <br> GND <br> **D5** (GPIO14) |
| **Rain Sensor** | VCC <br> GND <br> DO (Digital Out) | 3V3 / 5V <br> GND <br> **D6** (GPIO12) |

---

## 📊 การตั้งค่า Blynk 2.0 (Datastreams)

สร้าง Virtual Pins บน Blynk Console ดังนี้:

| Datastream | Virtual Pin | Data Type | Units / Values | Description |
| :--- | :--- | :--- | :--- | :--- |
| Temperature | `V0` | Double | °C (0-100) | ค่าอุณหภูมิ |
| Humidity | `V1` | Double | % (0-100) | ค่าความชื้นสัมพัทธ์ |
| Feel Like | `V2` | Double | °C (0-100) | ค่าดัชนีความร้อน |
| Day/Night Status | `V3` | String | กลางวัน / กลางคืน | สถานะแสง |
| Rain Status | `V4` | String | ฝนกำลังตก / ฝนไม่ตก | สถานะน้ำฝน |

---

## 💻 การติดตั้ง Library ใน Arduino IDE

ก่อนทำการ Compile โค้ด ต้องติดตั้ง Library ดังต่อไปนี้ผ่าน Library Manager:

* **Blynk** by Volodymyr Shymanskyy
* **DHT sensor library** by Adafruit
* **Adafruit Unified Sensor** by Adafruit

---

## 🚀 โครงสร้างโปรเจกต์ (Project Structure)

```text
├── Weather_Station_Lab7.ino   # โค้ดหลัก Arduino C++
└── README.md                  # เอกสารอธิบายโปรเจกต์
