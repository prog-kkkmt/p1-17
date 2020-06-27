#импорт модулей для работы бота 
import keybord as kb
import logging
import asyncio
import pyowm
import geo
import aiogram.types.base

from aiogram import Bot, Dispatcher, executor, types #импорт модулей для работы с TelegramBotAPI

from sqlighter import SQLighter #импорт класса для работы с БД

#задаем уровень логов
logging.basicConfig(level=logging.INFO)

#инициализация бота
bot = Bot(token='1296584769:AAEu7y4Qjz9y7k6zA0rn8Tz9PmzUnJA4mB0')

dp = Dispatcher(bot)

# инициализация соединения с БД
db = SQLighter('db.db')

#команда активации подписки
@dp.message_handler(commands=['subscribe'])#если сообщение от пользователя 'subscribe' делать дальнейшие команды

#async def — определяет native coroutine function, результатом вызова которой будет объект-сопрограмма native coroutine, пока еще не запущенная.
async def subscribe(message: types.Message):

    #проверка на наличие подписки у пользователя
	if(not db.subscriber_exists(message.from_user.id)):
		db.add_subscriber(message.from_user.id)
	else:
		db.update_subscription(message.from_user.id, True)

#async def —  Сопрограмма  (coroutine) асинхронная функция 
async def subscribe(message: types.Message):

    #проверка на наличие подписки у пользователя
	if(not db.subscriber_exists(message.from_user.id)):
		db.add_subscriber(message.from_user.id)
	else:
		db.update_subscription(message.from_user.id, True)
		'''Ключевое слово await приостанавливает выполнение текущей сопрограммы (coroutine) и вызывает  message.answer.'''
		await message.answer("Вы подписались на бота")
#погода
@dp.message_handler(commands = ['weather'])
async def weather(message: types.Message):
          await message.answer("Введите город:")
          @dp.message_handler(content_types=["text"])
          async def get_city(message):
                  city = message.text # сохраняем данные о городе
                  await message.answer(geo.weatherd(city)) # печать в чат погоды    

#вывод кнопки команд на экран
@dp.message_handler(commands=['start'])
async def buttons(message: types.Message):
    await message.answer('btn', reply_markup=kb.markup3)

#скрытие с экрана кнопок
@dp.message_handler(commands=['remove'])
async def removekb(message: types.Message):
    await message.answer('remove_kb', reply_markup=kb.ReplyKeyboardRemove())

#запуск бота
if __name__ == '__main__':
	executor.start_polling(dp, skip_updates=True)
