#импорт модулей для работы с клавиатурой и кнопками
from aiogram.types import InlineKeyboardButton, InlineKeyboardMarkup, ReplyKeyboardRemove, KeyboardButton, ReplyKeyboardMarkup 

#кнопки для меню
button1 = InlineKeyboardButton(" ", callback_data='btn1')
button2 = InlineKeyboardButton(" ", callback_data='btn2')
button3 = InlineKeyboardButton(" ", callback_data='btn3')
button4 = InlineKeyboardButton(" ", callback_data='btn4')
button5 = InlineKeyboardButton(" ", callback_data='btn5')
button6 = InlineKeyboardButton(" ", callback_data='btn6')
button7 = InlineKeyboardButton(" ", callback_data='btn7')
button8 = InlineKeyboardButton(" ", callback_data='btn8')
button9 = InlineKeyboardButton(" ", callback_data='btn9')

inline_kb1 = InlineKeyboardMarkup()
#печать в чат поля 3*3 из кнопок для будущего меню
inline_kb1.add(
	button1, button2, button3, button4, button5, button6, button7, button8, button9
)
#кнопки для виртуальной клавиатуры
button10 = KeyboardButton('/weather')
button11 = KeyboardButton('/subscribe')
button12 = KeyboardButton('/unsubscribe')
#вывод на экран виртуальной клавиатуры с кнопками
markup3 = ReplyKeyboardMarkup().row(
    button10, button11, button12
)
