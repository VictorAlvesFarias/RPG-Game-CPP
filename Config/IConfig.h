#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Entities/Item/IItem.h"

class Config{
    public: const Item items[50] {
        Item("Pocao de Vida Pequena", true, 50, 0, 0, 0),    // Pocao que cura 50 pontos de vida
        Item("Pocao de Vida Grande", true, 100, 0, 0, 0),    // Pocao que cura 100 pontos de vida
        Item("Espada de Ferro", false, 0, 0, 0, 25),         // Espada com 25 de dano
        Item("Escudo de Madeira", false, 0, 0, 0, 0),        // Escudo, sem cura ou dano
        Item("Elixir de Mana", true, 0, 0, 0, 0),            // Elixir que restaura mana
        Item("Armadura de Couro", false, 0, 50, 0, 0),       // Armadura que aumenta a vida maxima em 50
        Item("Anel Magico", false, 0, 20, 1, 10),            // Anel magico com 20 de vida extra, 1 slot de cinto e 10 de dano
        Item("Bomba Explosiva", true, 0, 0, 0, 50),          // Bomba que causa 50 de dano
        Item("Botas de Velocidade", false, 0, 0, 0, 0),      // Botas que aumentam a velocidade
        Item("Cinto de Utilidades", false, 0, 0, 5, 0),      // Cinto que adiciona 5 slots de cinto
        Item("Pocao de Veneno", true, 0, 0, 0, 0),           // Pocao que envenena o inimigo
        Item("Martelo de Guerra", false, 0, 0, 0, 35),       // Martelo que causa 35 de dano
        Item("Armadura de Aco", false, 0, 100, 0, 0),        // Armadura que aumenta a vida maxima em 100
        Item("Elixir de Forca", true, 0, 0, 0, 0),           // Elixir que aumenta a forca
        Item("Espada Flamejante", false, 0, 0, 0, 40),       // Espada com 40 de dano e efeitos de fogo
        Item("Pocao de Resistencia", true, 0, 0, 0, 0),      // Pocao que aumenta a resistencia temporariamente
        Item("Escudo de Aco", false, 0, 0, 0, 0),            // Escudo com maior resistencia
        Item("Pocao de Cura Instantanea", true, 200, 0, 0, 0), // Pocao que cura instantaneamente 200 de vida
        Item("Arco Longo", false, 0, 0, 0, 30),              // Arco com 30 de dano
        Item("Flechas Envenenadas", true, 0, 0, 0, 15),      // Flechas que causam 15 de dano e envenenam o inimigo
        Item("Pocao de Invisibilidade", true, 0, 0, 0, 0),   // Pocao que torna o usuario invisivel
        Item("Cajado Magico", false, 0, 0, 0, 50),           // Cajado que causa 50 de dano magico
        Item("Pocao de Velocidade", true, 0, 0, 0, 0),       // Pocao que aumenta a velocidade temporariamente
        Item("Chicote de Fogo", false, 0, 0, 0, 45),         // Chicote que causa 45 de dano com efeito de fogo
        Item("Pocao de Energia", true, 0, 0, 0, 0),          // Pocao que restaura energia
        Item("Faca de Caca", false, 0, 0, 0, 20),            // Faca que causa 20 de dano
        Item("Bastao de Gelo", false, 0, 0, 0, 40),          // Bastao que causa 40 de dano com efeito de gelo
        Item("Elixir de Inteligencia", true, 0, 0, 0, 0),    // Elixir que aumenta a inteligencia
        Item("Pocao de Furia", true, 0, 0, 0, 0),            // Pocao que aumenta o dano temporariamente
        Item("Elmo de Ferro", false, 0, 0, 0, 0),            // Elmo de ferro que oferece protecao extra
        Item("Espada do Dragao", false, 0, 0, 0, 60),        // Espada lendaria que causa 60 de dano
        Item("Pocao de Defesa", true, 0, 0, 0, 0),           // Pocao que aumenta a defesa temporariamente
        Item("Escudo do Dragao", false, 0, 0, 0, 0),         // Escudo lendario que oferece grande resistencia
        Item("Espada Curta", false, 0, 0, 0, 15),            // Espada com 15 de dano
        Item("Lanca Longa", false, 0, 0, 0, 35),             // Lanca que causa 35 de dano
        Item("Elixir de Vida", true, 150, 0, 0, 0),          // Elixir que cura 150 de vida
        Item("Armadura de Dragao", false, 0, 200, 0, 0),     // Armadura lendaria que aumenta a vida maxima em 200
        Item("Elmo de Aco", false, 0, 0, 0, 0),              // Elmo de aco para protecao extra
        Item("Pocao de Cura Pequena", true, 25, 0, 0, 0),    // Pocao que cura 25 pontos de vida
        Item("Pocao de Cura Media", true, 75, 0, 0, 0),      // Pocao que cura 75 pontos de vida
        Item("Armadura de Ouro", false, 0, 150, 0, 0),       // Armadura que aumenta a vida maxima em 150
        Item("Machado de Batalha", false, 0, 0, 0, 45),      // Machado que causa 45 de dano
        Item("Pocao de Dano", true, 0, 0, 0, 0),             // Pocao que aumenta o dano temporariamente
        Item("Bastao do Trovão", false, 0, 0, 0, 60),        // Bastao magico que causa 60 de dano eletrico
        Item("Adaga Envenenada", false, 0, 0, 0, 30),        // Adaga que causa 30 de dano e envenena o inimigo
        Item("Pocao de Mana", true, 0, 0, 0, 0),             // Pocao que restaura mana
        Item("Arco Curto", false, 0, 0, 0, 20),              // Arco com 20 de dano
        Item("Lanca Envenenada", false, 0, 0, 0, 40),        // Lanca que causa 40 de dano e envenena o inimigo
        Item("Pocao de Defesa Absoluta", true, 0, 0, 0, 0)  
    };;
};