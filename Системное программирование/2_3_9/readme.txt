1. Создайте пустые файлы file1 и file2 в домашней директории.
2. Создайте директорию ~/default, и скопируйте в нее все файлы из /etc/default.
3. Создайте директорию ~/newdir, и переместите в нее файлы rsyslog и syslog-ng из ~/default.
4. Удалите директорию /var/cache/apt со всем поддиректориями и файлами (используйте команду sudo для удаления с правами суперпользователя).

touch file1 // создаем пустые файлы
touch file2 // создаем пустые файлы

написал cp -r /etc/default /home/box // Я скопировал целую папку default из /etc/default в /home/box 
можно было и перенести целую папку используя утилиту mv

следом напписал mkdir newdir и создал новую директорию, написал

cp ~/default/syslog-ng newdir //скопировал syslog-ng из ~/default в newdir
cp ~/default/rsyslog  newdir //скопировал rsyslog из ~/default в newdir 

sudo rm -rf apt удалил директорию apt с правами суперпользователя(sudo)

Все хорошо. 
Когда начнём программировать?
