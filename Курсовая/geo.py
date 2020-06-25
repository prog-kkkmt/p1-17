import geocoder
import pyowm


def weatherd(city):
    owm = pyowm.OWM('a7a5f151b3845f1d0a5979f764dbb267')
    mgr = owm.weather_manager()    
    observation = mgr.weather_at_place(city + ',rus')
    w = observation.weather
    temp = w.temperature('celsius')["temp"]
    wind = w.wind()["speed"]
    hum = w.humidity

    answer = "В городе " + city + " сейчас " + w.detailed_status + "\n---------------------"
    answer += "\nТемпература: " + str(temp) + "°C" + "\n---------------------" + "\nСкорость ветра: " + str(wind) + "м/с." + "\n---------------------" + "\nВлажность: " + str(hum) + "%" + "\n---------------------"
    return answer