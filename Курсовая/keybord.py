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

inline_kb1 = InlineKeyboardMarkup()

inline_kb1.add(
	button1, button2, button3, button4, button5, button6, button7, button8, button9
)

markup_request = ReplyKeyboardMarkup(resize_keyboard=True).add(
    KeyboardButton('Отправить свой контакт ☎️', request_contact=True)
).add(
    KeyboardButton('Отправить свою локацию 🗺️', request_location=True)
)