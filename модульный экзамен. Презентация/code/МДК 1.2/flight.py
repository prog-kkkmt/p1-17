# класс Рейс
class Flight:
    def __init__(self, idFlight, idStation, idBus, time):
        self.idFlight = idFlight # код рейса
        self.idStation = idStation # код станции
        self.idBus = idBus # код автобуса
        self.time = time # время отправления

    def getIdBus(self):
        """
        геттер кода автобуса

        Args:
            self: Объект класса.

        Returns:
            self.idBus: Код автобуса.

        Raises:
            
        """
        return self.idBus