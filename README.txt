Сигнатурный сканер предлагает пользователю возможность проверить любой исполняемый файл формата
.exe на наличие сигнатур, идентифицирующих образцы вредоносных файлов.

Чтобы проверить файл, введите его полное расположение, например: V:\Apps\DS4Updater.exe.

В папке также приложен файл cleanfile.exe, содержащий сигнатуру, соответствующему вредоносному файлу krypt.exe. Файл приложен в целях проверки возможностей приложения по идентификации вредоносного софта. При открытии файл запускает программу самоуничтожения компьютера в течение 6 (шести, six) секунд. Открывать напрямую строго не рекомендуется (см. "Испытания на атолле Бикини").

Далее необходимо ввести полное расположение файла, в котором хранится образец сигнатуры
вредоносного файла. Нажмите "1" вместо расположения файла, чтобы использовать образец по
умолчанию, хранящийся в папке с программой

При использовании своей сигнатуры необходимо указать расположение вашего файла.

ОБРАТИТЕ ВНИМАНИЕ, что хранящиеся в файле данные о сигнатуре должны строго иметь следующий вид:

Смещение|Сигнатура*Название образца

Например, 1276|Cardinal*krypt.exe

Выбранная Вами сигнатура (в примере выше: Cardinal) не должна содержать символы "|" и "*".
-----------------------------------------------------------------------------------------------

