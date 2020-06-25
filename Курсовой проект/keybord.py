from aiogram.types import InlineKeyboardButton, InlineKeyboardMarkup, ReplyKeyboardRemove, KeyboardButton, ReplyKeyboardMarkup

button1 = InlineKeyboardButton(" ", callback_data='btn1')
button2 = InlineKeyboardButton(" ", callback_data='btn2')
button3 = InlineKeyboardButton(" ", callback_data='btn3')
button4 = InlineKeyboardButton(" ", callback_data='btn4')
button5 = InlineKeyboardButton(" ", callback_data='btn5')
button6 = InlineKeyboardButton(" ", callback_data='btn6')
button7 = InlineKeyboardButton(" ", callback_data='btn7')
button8 = InlineKeyboardButton(" ", callback_data='btn8')
button9 = InlineKeyboardButton(" ", callback_data='btn9')

button10 = KeyboardButton('/weather')
button11 = KeyboardButton('/subscribe')
button12 = KeyboardButton('/unsubscribe')

markup3 = ReplyKeyboardMarkup().row(
    button10, button11, button12
)


inline_kb1 = InlineKeyboardMarkup()

inline_kb1.add(
	button1, button2, button3, button4, button5, button6, button7, button8, button9
)

