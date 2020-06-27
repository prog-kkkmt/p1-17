import pyowm #импорт модуля для работы с погодой

#погода
def weatherd(city):

    # инициализируем бота для работы с погодой
    owm = pyowm.OWM('a7a5f151b3845f1d0a5979f764dbb267')
    mgr = owm.weather_manager()    
    # получение информации о погоде в городе
    observation = mgr.weather_at_place(city + ',rus')
    # погода 
    w = observation.weather
    # температура
    temp = w.temperature('celsius')["temp"]
    # скорость ветра
    wind = w.wind()["speed"]
    # погода влажность
    hum = w.humidity
    # формирование ответа, выводимого в чат пользователю
    answer = "В городе " + city + " сейчас " + w.detailed_status + "\n---------------------"
    answer += "\nТемпература: " + str(temp) + "°C" + "\n---------------------" + "\nСкорость ветра: " + str(wind) + "м/с." + "\n---------------------" + "\nВлажность: " + str(hum) + "%" + "\n---------------------"
    return answer
