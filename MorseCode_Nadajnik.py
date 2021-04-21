import serial #biblioteka do komunikacji

port = input("Enter port: ") #zmienna z ustawionym przez użytkownika portem do komunikacji

ser = serial.Serial(port, 9600) #zainicjowanie płytki na wybranym porcie

myMessage = "" #zmienna do zapisu wiadomości

while 1: #pobieranie wiadomości w nieskończoność, dopóki nie wyłaczymy programu
	myMessage = input("Enter a message: ") #zapisanie wiadomości w zmiennej
	ser.write(myMessage.encode('UTF-8')) #wysłanie wiadomości przez port, z kodowaniem UTF-8