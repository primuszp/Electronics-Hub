# Sanguino

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

## Sanguino szoftverkörnyezet

Ahhoz, hogy programozni tudjuk a Sanguino-t az Arduino platform segítségével, hozzá kell adnunk az alaplapkezelő beállításokat és kódokat. Látogassuk meg a GitHub-on a [Sanguino add-on oldalát][6]. Másoljuk ki az alaplapkezelő URL-t:

```
https://raw.githubusercontent.com/Lauszus/Sanguino/master/package_lauszus_sanguino_index.json
```

Az Arduino fejlesztő környezetben a `Fájl -> Beállítások` menüponton keresztül adjuk hozzá az alaplapkezelő URL-khez:

`File -> Preferences -> Aditional Boards Manager Urls`

Ezután az `Eszközök` menüpontban válasszuk ki az `Alaplap -> Alaplap-kezelő...` menüpontot és a listában válasszuk ki és telepítsük a Sanguino alaplapot.

A fenti leírás tesztelve: Arduino IDE 1.6.7 és 1.8.6

További kapcsolódó linkek:
- http://lauszus.github.com/Sanguino/
- https://code.google.com/archive/p/sanguino/
- https://github.com/arduino/Arduino/wiki/Unofficial-list-of-3rd-party-boards-support-urls

[breadboard_wiring_diagram]: images/sanguino_breadboard_wiring_diagram.png "Próbaáramkör kapcsolási rajz"
[atmega644p_pinout]: images/atmega644p_pinout.jpg "ATmega644p chip lábkiosztása"
[atmega1284p_pinout]: images/atmega1284p_pinout.jpg "ATmega1284p chip lábkiosztása"

[1]: http://sanguino.wikidot.com
[2]: http://sanguino.wikidot.com/1-0kitassembly
[3]: http://sanguino.wikidot.com/breadboardsanguino
[4]: https://www.ebay.com/itm/ATMEGA1284-PU-ARDUINO-SANGUINO-KIT-mit-5V-Spannungsstabilisator-MCU-A933/262787339584?hash=item3d2f589540:g:jrkAAOSw-0xYaN6O:rk:17:pf:0
[5]: https://www.ebay.com/itm/ATMEGA1284-PU-mit-with-ARDUINO-SANGUINO-bootloader-mit-ohne-Sockel-AVR/262963117895?hash=item3d39d2bf47:m:mUIEzhLziPVzq45urscwedA:rk:23:pf:0
[6]: https://github.com/Lauszus/Sanguino
[7]: http://www.pighixxx.net/