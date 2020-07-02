# импорт всех файлов с библиотеки tkinter
from tkinter import *
from tkinter import ttk

# импорт только asksaveasfile из filedialog
# позволяет сохранить файл в любом расширении
from tkinter.filedialog import asksaveasfile

root = Tk()
root.geometry('200x250')


""" функция вызывается, когда пользователь нажимает на
    кнопку 'сохранить'. Появляется окно для выбора места сохранения"""
def save():
    files = [('All Files', '*.*'),
             ('Text Document', '*.txt')]
    file = asksaveasfile(filetypes=files, defaultextension=files)
    for i in range(len(list)):
        file.write(list[i])
        file.write('\n')
    file.close()

f = open('unsorted.txt', 'r')

list = []
# считываем каждую линию
for line in f:
    # считываем каждое слово
    for word in line.split():
        list.append(word)

# сортируем список всех слов
list.sort()

# создаём виджет для отображения сортированного текста
listbox = Listbox(root)
listbox.pack()

# добавляем в окно для текста сортированный текст
for item in list:
    listbox.insert(END, item)

# создаём ползунок для полного отображения текста в виджете с текстом
scroll = Scrollbar(command=listbox.yview)
scroll.pack(side=LEFT, fill=Y)

listbox.config(yscrollcommand=scroll.set)
btn = ttk.Button(root, text='Сохранить', command=lambda: save())
btn.pack(side=TOP, pady=20)

mainloop()