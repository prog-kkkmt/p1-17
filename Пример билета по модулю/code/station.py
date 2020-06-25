# класс Станция
class Station:
    def __init__(self, idS, name):
        self.idS = idS # код станции
        self.name = name # название станции

    # функция строкового представления объекта
    def __repr__(self):
        return self.name

    def getId(self):
        """
        геттер кода станции

        Args:
            self: Объект класса.

        Returns:
            self.idS: Код станции.

        Raises:
            
        """
        return self.idS