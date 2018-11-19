#!/usr/bin/python
import sys
import os
import tkinter as tk

class Application(tk.Frame):
    def __init__(self, master=None):
        super().__init__(master)
        self.master = master
        self.pack()
        self.farois()
        self.dFarois()
        self.emergencia()
        self.buzzer()
        self.decolar()
        self.pousar()
        self.tremPouso()
        self.ligaMotor()
        self.centraliza()
        self.desligaMotor()
        self.esquerda()
        self.direita()

# Liga Farois
    def farois(self):
        self.liga = tk.Button(self)
        self.liga["text"] = "Ligar Farois"
        self.liga["command"] = self.ligaFarois
        self.liga.pack(side="top")
        self.quit = tk.Button(self, text="QUIT", fg="red",
                              command=self.master.destroy)
        self.quit.pack(side="bottom")

    def ligaFarois(self):
        print("Ligando faróis")
        os.system('sudo python3.6 comandos/farol_liga.py')

# Desliga farois
    def dFarois(self):
        self.desliga = tk.Button(self)
        self.desliga["text"] = "Desligar Farois"
        self.desliga["command"] = self.desligaFarois
        self.desliga.pack(side="top")

    def desligaFarois(self):
        print("Desligando faróis")
        os.system('sudo python3.6 comandos/farol_desliga.py')

# Emergência
    def emergencia(self):
        self.emergencia = tk.Button(self)
        self.emergencia["text"] = "Alarme Emergência"
        self.emergencia["command"] = self.ligaEmergencia
        self.emergencia.pack(side="top")

    def ligaEmergencia(self):
        print("Acionando Emergência")
        os.system('sudo python3.6 comandos/emergencia.py')

# buzzer
    def buzzer(self):
        self.buzzer = tk.Button(self)
        self.buzzer["text"] = "Acionar Buzzer"
        self.buzzer["command"] = self.ligaBuzzer
        self.buzzer.pack(side="top")

    def ligaBuzzer(self):
        print("Acionando Buzzer")
        os.system('sudo python3.6 comandos/buzzer.py')

# decola
    def decolar(self):
        self.decola = tk.Button(self)
        self.decola["text"] = "Decolar"
        self.decola["command"] = self.subir
        self.decola.pack(side="top")

    def subir(self):
        print("Decolando, apertem os cintos")
        os.system('sudo python3.6 comandos/decolaY.py')

# pousar
    def pousar(self):
        self.pousar = tk.Button(self)
        self.pousar["text"] = "Pousar"
        self.pousar["command"] = self.pousa
        self.pousar.pack(side="top")

    def pousa(self):
        print("Pousando, apertem os cintos")
        os.system('sudo python3.6 comandos/pousaY.py')

# trem de pouso
    def tremPouso(self):
        self.tremP = tk.Button(self)
        self.tremP["text"] = "Acionar trem de pouso"
        self.tremP["command"] = self.trem
        self.tremP.pack(side="top")

    def trem(self):
        print("Acionar trem de pouso")
        os.system('sudo python3.6 comandos/tremDePouso.py')

# liga motor
    def ligaMotor(self):
        self.Motor = tk.Button(self)
        self.Motor["text"] = "Ligar motor"
        self.Motor["command"] = self.motorLiga
        self.Motor.pack(side="top")

    def motorLiga(self):
        print("Ligando motor")
        os.system('sudo python3.6 comandos/motor.py')

# centraliza
    def centraliza(self):
        self.centro = tk.Button(self)
        self.centro["text"] = "Centralizando avião"
        self.centro["command"] = self.centralizar
        self.centro.pack(side="top")

    def centralizar(self):
        print("Centraliza avião")
        os.system('sudo python3.6 comandos/centralizaY.py')

# desliga motor
    def desligaMotor(self):
        self.desliga = tk.Button(self)
        self.desliga["text"] = "Desliga Motor"
        self.desliga["command"] = self.deslMotor
        self.desliga.pack(side="top")

    def deslMotor(self):
        print("Desliga motor")
        os.system('sudo python3.6 comandos/deslMotor.py')

# Inclina esquerda
    def esquerda(self):
        self.esquerda = tk.Button(self)
        self.esquerda["text"] = "Inclinar à esquerda"
        self.esquerda["command"] = self.inclinaEsquerda
        self.esquerda.pack(side="top")

    def inclinaEsquerda(self):
        print("Inclinando avião para esquerda")
        os.system('sudo python3.6 comandos/esquerda.py') 

# Inclina direita
    def direita(self):
        self.direita = tk.Button(self)
        self.direita["text"] = "Inclinar à direita"
        self.direita["command"] = self.inclinadireita
        self.direita.pack(side="top")

    def inclinadireita(self):
        print("Inclinando avião para direita")
        os.system('sudo python3.6 comandos/direita.py')               

root = tk.Tk()
app = Application(master=root)
app.mainloop()
