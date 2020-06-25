import keybord as kb
import logging
import asyncio
import pyowm
import geo
import aiogram.types.base

from aiogram import Bot, Dispatcher, executor, types

from sqlighter import SQLighter

# задаем уровень логов
logging.basicConfig(level=logging.INFO)

# инициализируем бота
bot = Bot(token='1296584769:AAEu7y4Qjz9y7k6zA0rn8Tz9PmzUnJA4mB0')

dp = Dispatcher(bot)

# инициализируем соединение с БД
db = SQLighter('db.db')

# Команда активации подписки
@dp.message_handler(commands=['subscribe'])
async def subscribe(message: types.Message):
	if(not db.subscriber_exists(message.from_user.id)):
		db.add_subscriber(message.from_user.id)
	else:
		db.update_subscription(message.from_user.id, True)
	
	await message.answer("Вы подписались на бота")

# Команда отписки
@dp.message_handler(commands=['unsubscribe'])
async def unsubscribe(message: types.Message):
	if(not db.subscriber_exists(message.from_user.id)):
		db.add_subscriber(message.from_user.id, False)
		await message.answer("Вы итак не подписаны.")
	else:
		db.update_subscription(message.from_user.id, False)
		await message.answer("Вы отписаны от рассылки.")

#погода
@dp.message_handler(commands = ['weather'])
async def weather(message: types.Message):
          await message.answer("Введите город:")
          @dp.message_handler(content_types=["text"])
          async def get_city(message):
                  city = message.text # сохраняем данные
                  await message.answer(geo.weatherd(city))
          
 

#кнопки
@dp.message_handler(commands=['start'])
async def buttons(message: types.Message):
    await message.answer('btn', reply_markup=kb.markup3)

#удаление кнопок
@dp.message_handler(commands=['remove'])
async def removekb(message: types.Message):
    await message.answer('remove_kb', reply_markup=kb.ReplyKeyboardRemove())

# запускаем лонг поллинг
if __name__ == '__main__':
	executor.start_polling(dp, skip_updates=True)
