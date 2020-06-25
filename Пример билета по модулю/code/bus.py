# класс Автобус
class Bus:
    def __init__(self, idBus, label, number, capacity):
        self.idBus = idBus # id автобуса
        self.label = label # марка автобуса
        self.number = number # номер автобуса
        self.capacity = capacity # вместительность автобуса

    def getCapacity(self):
        """
        геттер вместительности автобуса

        Args:
            self: Объект класса.

        Returns:
            self.capacity: Вместительность автобуса.

        Raises:
            
        """
        return self.capacity