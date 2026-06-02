# Robot WallFollower

![Skematik Fritzing](https://github.com/ElectroBoi/BAB-3-2526/blob/main/Skematik/Fritzing.png)

[![Skematik](https://img.shields.io/badge/Skematik_PDF-green?style=for-the-badge)](https://github.com/ElectroBoi/BAB-3-2526/blob/main/Skematik/AiO%20MuRo%20Robot%20V2.pdf)

### Pin Connections Table

| **Modul** | **Pin Modul** | **Pin Arduino Nano** |
|:----------|:--------------|:---------------------|
| **L298N Motor Driver** | ENA | `D5` |
| | IN1 | `D3` |
| | IN2 | `D4` |
| | IN3 | `D2` |
| | IN4 | `D7` |
| | ENB | `D6` |
| **Ultrasonik Depan** | ECHO | `D10` |
| | TRIG | `D11` |
| **Ultrasonik Kiri** | ECHO | `D9` |
| | TRIG | `D8` |
| **Ultrasonik Kanan** | ECHO | `D13` |
| | TRIG | `D12` |
| **Bluetooth HC-05** | TX | `D15` |
| | RX | `D16` |
| **Tombol Mode** |  | `A6` |
| **LED Indikator Mode** |  | `D17` |

| **Modul** | **Pin Modul** | **Pin IO PCF8574T (0x20)** |
|:----------|:--------------|:---------------------|
| **LF1 (Ujung Kiri)** | ENA | `0` |
| **LF2 (Kiri)** | ENA | `2` |
| **LF7 (Kanan)** | ENA | `6` |
| **LF8 (Ujung Kanan)** | ENA | `7` |


---


### Percobaan Wall Follower

Robot akan mengikuti dinding menggunakan sensor ultrasonik.

#### Langkah Kerja:

1. Pastikan modul ultrasonik terpasang dengan benar
2. Hubungkan mikrokontroler ke komputer via kabel Micro USB
3. Buka Arduino IDE
4. Masukan program Wall Follower pada Arduino IDE (Pastikan Program yang dituliskan benar!)
5. Upload program ke Arduino Nano
6. Pasang baterai pada robot
7. Letakkan robot di arena Wall Follower
8. Nyalakan switch dan lihat robot beraksi


---

## 🛠️ Komponen yang Digunakan

| Komponen | Deskripsi |
|----------|-----------|
| Arduino Nano | Mikrokontroler utama |
| L298N Motor Driver | Pengendali motor DC |
| HC-05 | Modul Bluetooth |
| HC-SR04/05 (3x) | Sensor ultrasonik |
| Sensor IR + PCF8574T | Sensor inframerah dengan I2C expander |
| Baterai | Power supply untuk robot |
| Switch | On/Off robot |
| Custom PCB | Board integrasi semua komponen |

---

## 📚 Resources & Links

- [Repository Lengkap](https://github.com/ElectroBoi/BAB-3-2526)
- [Folder Program](https://github.com/ElectroBoi/BAB-3-2526/tree/main/Program)
- [Folder Images](https://github.com/ElectroBoi/BAB-3-2526/tree/main/images)

---

## 📄 Lisensi

Project ini dibuat untuk keperluan **Abdimas Robot PSMURO**. Silakan gunakan dan modifikasi sesuai kebutuhan pembelajaran.

---

<div align="center">

**Pusat Studi. Multimedia dan Robotika**


</div>
