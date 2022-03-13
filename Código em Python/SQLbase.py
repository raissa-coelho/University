import sqlite3
from sqlite3 import Error

from django.db import connection

def create_conection(path):
    connection = None
    try:
        connection = sqlite3.connect(path)
        print("Conexão feita com sucesso.")
    except Error as e:
        print(f"O erro '{e}' ocorreu.")
    
    return connection

if __name__ == '__main__':
    create_conection(r"C:\Users\raiss\Downloads\Programas\Python\SQLfiles\Database\pythonsqlite.db")

# criando uma Database em python
