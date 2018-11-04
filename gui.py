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
        os.system('sudo python3.6 ../xbee/farol_liga.py')

# Desliga farois
    def dFarois(self):
        self.desliga = tk.Button(self)
        self.desliga["text"] = "Desligar Farois"
        self.desliga["command"] = self.desligaFarois
        self.desliga.pack(side="top")

    def desligaFarois(self):
        print("Desligando faróis")
        os.system('sudo python3.6 ../xbee/farol_desliga.py')

# Emergência
    def emergencia(self):
        self.emergencia = tk.Button(self)
        self.emergencia["text"] = "Alarme Emergência"
        self.emergencia["command"] = self.ligaEmergencia
        self.emergencia.pack(side="top")

    def ligaEmergencia(self):
        print("Acionando Emergência")
        os.system('sudo python3.6 ../xbee/emergencia.py')

# buzzer
    def buzzer(self):
        self.buzzer = tk.Button(self)
        self.buzzer["text"] = "Acionar Buzzer"
        self.buzzer["command"] = self.ligaBuzzer
        self.buzzer.pack(side="top")

    def ligaBuzzer(self):
        print("Acionando Buzzer")
        os.system('sudo python3.6 ../xbee/buzzer.py')

# decola
    def decolar(self):
        self.decola = tk.Button(self)
        self.decola["text"] = "Decolar"
        self.decola["command"] = self.subir
        self.decola.pack(side="top")

    def subir(self):
        print("Decolando, apertem os cintos")
        #os.system('sudo python3.6 ../xbee/buzzer.py')

# pousar
    def pousar(self):
        self.pousar = tk.Button(self)
        self.pousar["text"] = "Pousar"
        self.pousar["command"] = self.pousa
        self.pousar.pack(side="top")

    def pousa(self):
        print("Pousando, apertem os cintos")
        #os.system('sudo python3.6 ../xbee/buzzer.py')

# trem de pouso
    def tremPouso(self):
        self.trem = tk.Button(self)
        self.trem["text"] = "Acionar trem de pouso"
        self.trem["command"] = self.trem
        self.trem.pack(side="top")

    def trem(self):
        print("Acionar trem de pouso")
        #os.system('sudo python3.6 ../xbee/buzzer.py')

root = tk.Tk()
app = Application(master=root)
app.mainloop()
