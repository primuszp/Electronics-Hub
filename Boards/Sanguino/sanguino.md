
# Tartalom

Jelen műszaki dokumentáció az alábbi fő fejezetekből áll:

- [Sanguino ismertető](#sanguino-ismertető)
- [Sanguino próbapanelen](#sanguino-próbapanelen)
- [Sanguino nyomtatott áramkörön](#sanguino-nyomtatott-áramkörön)
- [Szoftverkörnyezet telepítése](#sanguino-szoftverkörnyezet)
- [Programozó bekötése](#programozó-bekötése)

Remélem sokaknak megjön a kedve egy Arduino alapú fejlesztőpanel megépítéséhez ezen leírás alapján.

# Sanguino ismertető

Mindannyian szeretjük az Arduino platformot, azon belül is az UNO alaplaphoz húz leginkább a szívünk. Sajnos olykor, az ATmega 328P chip tudása nem elég a feladatunk megoldásához, ezért nagyobb tudású mikrovezérlőt kell keresnünk. Ekkor kerül leginkább a képbe az egyik legnagyobb tudású Arduino hardver, az Arduino MEGA. Tudása minden téren felülmúlja az UNO és a NANO képességeit, de egyben a legtöbb feladathoz sok is. Főleg akkor, ha csak egy kicsit nagyobb memóriára, vagy néhány plusz lábra, megszakításra vagy soros portra lenne szükségünk, hogy befejezzük a projektet. Felmerül a kérdés, nincs semmi az UNO és a MEGA között? Szerencsére van, és ez a Sanguino!

A [Sanguino projekt][1] az [ATmega 644P][atmega644p_pinout] és [1284P][atmega1284p_pinout] chipeket támogatja és kompatibilis a standard Arduino szoftverfejlesztő környezettel és a legtöbb könyvtárral.

A Sanguino tudásban arany középutat képvisel az UNO és a MEGA között, a legfontosabb különbségeket a táblázatban olvashatjuk:

| Board         | Arduino UNO | Sanguino | Arduino MEGA |
|---------------|-------------|----------|--------------|
| ATmega Chip   | 328P        | 1284P    | 2560P        |
| RAM           | 2K          | 16K      | 8K           |
| Flash         | 32K         | 128K     |  256K        |
| EEPROM        | 1K          | 4K       | 4K           |
| UART          | 1           | 2        | 4            |
| IO Pins       | 23          | 32       | 54           |
| Interrupts    | 2           | 3        | 8            |
| Analog Inputs | 6           | 8        | 16           |

Az ATmega 644P és 1284P chip lábkiosztása (Arduino pins) itt érhető el:
- [ATmega 644P][atmega644p_pinout] by [PIGHIXXX (2013)][7]
- [ATmega 1284P][atmega1284p_pinout] by [PIGHIXXX (2013)][7]

## Sanguino próbapanelen

Először próbapanelen érdemes összeállítani áramkörünket. A legfontosabb [lépéseket][3] a Sanguino projektoldalon is elolvashatjuk.

Kezdőknek ajánlatos vásárolni egy építőkészletet, ahol már a mikrovezérlőre az Arduino bootloader fel van töltve. Az eBay-en találhatunk előre összeállított építőkészleteket (pl. Just-Honest Elektronische):

- [ATMEGA1284-PU SANGUINO kompatibel KIT mit 5V Spannungsstabilisator / 5V Regulator][4]
- [ATMEGA1284-PU mit / with ARDUINO (SANGUINO) bootloader mit/ohne Sockel AVR][5]

A legfontosabb alkatrészek listája:

- 1 x ATMEGA1284-PU chip (Sanguino bootloader)
- 1 x lemezes IC foglalat (40 láb)
- 2 x 22pF kerámia kondenzátor
- 1 x 16MHz kvarc kristály
- 1 x nyomógomb (6*6*5mm)
- 1 x 10KOhm ellenállás (0.25W)
- 1 x 7805 1.5A 5V feszültség szabályozó
- 2 x 0.1uF / 100nF kerámia kondenzátor
- 1 x 10uF / 25V elektrolit kondenzátor
- 1 x 100uF / 25V elektrolit kondenzátor
- 1 x zöld LED (3mm)
- 1 x vörös LED (3mm)
- 2 x 330Ohm ellenállás (0.25W)

A próbaáramkör kapcsolási rajza:

![A próbaáramkör kapcsolási rajza][breadboard_wiring_diagram]

Az összeszerelés lépéseit a lenti videó mutatja be részletesen:

<a href="http://www.youtube.com/watch?feature=player_embedded&v=yLRLbM6X_KM" target="_blank"><img src="http://img.youtube.com/vi/yLRLbM6X_KM/0.jpg" alt="Sanguino próbapanelen videó" width="480" height="360" border="5"/></a>

## Sanguino nyomtatott áramkörön

Célszerű a dugaszolós próbapanelen összerakott Sanguino kapcsolást nyomtatott áramkörre átültetni, és így egy sokkal jobban felhasználható panelt építeni belőle.

Első feladatunk, hogy meglátogassuk a Sanguino Wiki oldalát és onnan letöltsük a Sanguino panel nyomtatott áramkör terveit. Sajnos a megadott link már nem működik, de a [Google Code archívumából][8] még elérhetőek:

[Sanguino PCB letöltése][8]

A panel rajzolata EAGLE szoftverben készült, de szerencsére a Gerber fájlok is mellékelve vannak, így elég csak azt kedvenc gyártónk számára átküldeni. Akik nem annyira jártasak ezen a területen azok kész panelt is [rendelhetnek][10].

Ha megszereztük a nyomtatott áramkört, hozzá is kezdhetünk a munkához. A teljes összeszelés lépésről lépésre megtalálható a [Sanguino Wiki][2] oldalán.

![Sanguino (PCB) nyomtatott áramkör megépítéshez szükséges alkatrészek][sanguino_components]

A szükséges építőelemek listája:

- 1 x ATMEGA1284-PU chip (Sanguino bootloader)
- 1 x DIL 40 lemezes IC foglalat (40 láb)
- 2 x Tüskesor, egyenes, tördelhető, RM2, 1x40 pin
- 1 x Tüskesor, 90°, tördelhető, 1x20 pin
- 1 x Tüskesor, egyenes 2x3 pin (ICSP)
- 1 x 10KOhm ellenállás (0.25W)
- 2 x 22pF kerámia kondenzátor
- 4 x 100nF kerámia kondenzátor
- 2 x 100uF ELCO
- 1 x 16MHz kvarc kristály
- 1 x zöld LED (3mm)
- 1 x vörös LED (3mm)
- 2 x 1KOhm ellenállás (0.25W)
- 1 x dióda 1N404 400V 1A
- 1 x nyomógomb (6*6*5mm)
- 1 x jumper, RM2,54 mm
- 1 x apa szalagkábel csatlakozó, egyenes 10p 2x5 (JTAG)
- 1 x tápegység aljzat 2,1x5,5 mm
- 1 x tolókapcsoló NYÁK-hoz (SPDT)
- 1 x 7805 1.5A 5V feszültség szabályozó

Az összeszerelés lépéseit a lenti videó mutatja be részletesen:

<a href="http://www.youtube.com/watch?feature=player_embedded&v=le3tJvQLjOY" target="_blank"><img src="http://img.youtube.com/vi/le3tJvQLjOY/0.jpg" alt="Sanguino próbapanelen videó" width="480" height="360" border="5"/></a>

## Sanguino szoftverkörnyezet

Ahhoz, hogy programozni tudjuk a Sanguino-t az Arduino platform segítségével, hozzá kell adnunk az alaplapkezelő beállításokat és kódokat. Látogassuk meg a GitHub-on a [Sanguino add-on oldalát][6]. Másoljuk ki az alaplapkezelő URL-t:

```
https://raw.githubusercontent.com/Lauszus/Sanguino/master/package_lauszus_sanguino_index.json
```

Az Arduino fejlesztő környezetben a `Fájl -> Beállítások` menüponton keresztül adjuk hozzá az alaplapkezelő URL-khez:

`File -> Preferences -> Aditional Boards Manager Urls`

Ezután az `Eszközök` menüpontban válasszuk ki az `Alaplap -> Alaplap-kezelő...` menüpontot és a listában válasszuk ki és telepítsük a Sanguino alaplapot.

A fenti leírás tesztelve: Arduino IDE 1.6.7 és 1.8.6

## Programozó bekötése

Első példaprogramunk feltöltéséhez az USB programozót kell a panelhez illeszteni. Az USB-TTL soros programozó (FTDI Chip) oldalon a bekötést az ábrának megfelelően kell elvégezni:

![FT232 Mini USB-TTL soros programozó (5V és 3.3V)][FT232_mini_usb_ttl]

Magyarázat:

- GND : Föld
- CTS : Clear To Send
- VCC : +5V
- TXD : Adás (kimenet)
- RXD : Vétel (bemenet)
- DTR : Data Terminal Ready

Sanguino oldalon hasonló, csak TX és RX lábak vannak felcserélve.

# További kapcsolódó linkek

- [Sanguino add-on for the Arduino IDE](http://lauszus.github.com/Sanguino/)
- [Google Code - Sanguino repo](https://code.google.com/archive/p/sanguino/)
- [Unofficial list of 3rd party boards](https://github.com/arduino/Arduino/wiki/Unofficial-list-of-3rd-party-boards-support-urls)

[breadboard_wiring_diagram]: images/sanguino_breadboard_wiring_diagram.png "Próbaáramkör kapcsolási rajz"
[atmega644p_pinout]: images/atmega644p_pinout.jpg "ATmega644p chip lábkiosztása"
[atmega1284p_pinout]: images/atmega1284p_pinout.jpg "ATmega1284p chip lábkiosztása"
[sanguino_components]: images/sanguino_components.jpg "Sanguino nyomtatott áramkör alkatrészei"
[FT232_mini_usb_ttl]: images/ft232_usb_ttl.jpg "FT232 Mini USB-TTL"

[1]: http://sanguino.wikidot.com
[2]: http://sanguino.wikidot.com/1-0kitassembly
[3]: http://sanguino.wikidot.com/breadboardsanguino
[4]: https://www.ebay.com/itm/ATMEGA1284-PU-ARDUINO-SANGUINO-KIT-mit-5V-Spannungsstabilisator-MCU-A933/262787339584?hash=item3d2f589540:g:jrkAAOSw-0xYaN6O:rk:17:pf:0
[5]: https://www.ebay.com/itm/ATMEGA1284-PU-mit-with-ARDUINO-SANGUINO-bootloader-mit-ohne-Sockel-AVR/262963117895?hash=item3d39d2bf47:m:mUIEzhLziPVzq45urscwedA:rk:23:pf:0
[6]: https://github.com/Lauszus/Sanguino
[7]: http://www.pighixxx.com
[8]: https://code.google.com/archive/p/sanguino/downloads
[9]: https://www.tindie.com/products/t0mpr1c3/sanguino-atmega1284p-development-board-pcb/
[10]: https://web.archive.org/web/20131121050526/http://sanguino.cc:80/