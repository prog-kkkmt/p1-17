import keybord as kb
import config
import logging
import asyncio
import pyowm
import geo as g
import json
import telebot
from datetime import datetime

from aiogram import Bot, Dispatcher, executor, types

import aiogram.types.base

from sqlighter import SQLighter

# задаем уровень логов
logging.basicConfig(level=logging.INFO)

# инициализируем бота
bot = Bot(token=config.API_TOKEN)
owm = pyowm.OWM ('cc16c267326fd725e6c6dc2025143c34')
dp = Dispatcher(bot)

# инициализируем соединение с БД
db = SQLighter('db.db')

# Команда активации подписки
@dp.message_handler(commands=['subscribe'])
async def subscribe(message: types.Message):
	if(not db.subscriber_exists(message.from_user.id)):
		# если юзера нет в базе, добавляем его
		db.add_subscriber(message.from_user.id)
	else:
		# если он уже есть, то просто обновляем ему статус подписки
		db.update_subscription(message.from_user.id, True)
	
	await message.answer("Вы успешно подписались на рассылку!\nЖдите, скоро выйдут новые обзоры и вы узнаете о них первыми =) А вы подписались на Raid Shadow Legends?????????????????????????????????????????")

# Команда отписки
@dp.message_handler(commands=['unsubscribe'])
async def unsubscribe(message: types.Message):
	if(not db.subscriber_exists(message.from_user.id)):
		# если юзера нет в базе, добавляем его с неактивной подпиской (запоминаем)
		db.add_subscriber(message.from_user.id, False)
		await message.answer("Вы итак не подписаны.")
	else:
		# если он уже есть, то просто обновляем ему статус подписки
		db.update_subscription(message.from_user.id, False)
		await message.answer("Вы успешно отписаны от рассылки.")

#кретсики нолики
@dp.message_handler(commands=['krest'])
async def process_start_command(message: types.Message):
    await message.answer("cocи", reply_markup=kb.inline_kb1)

@dp.message_handler(commands=['goe'])
async def subscribe(message: types.Message):
	db.get_geolocation((message.from_user.id, True)
	#await message.answer(reply_markup = g.lol)



# запускаем лонг поллинг
if __name__ == '__main__':
	#dp.loop.create_task( scheduled(10)) # пока что оставим 10 секунд (в качестве теста)
	executor.start_polling(dp, skip_updates=True)
