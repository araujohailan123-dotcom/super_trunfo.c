Este projeto é uma implementação do clássico jogo Super Trunfo, desenvolvido em linguagem C, executado via terminal.

O jogador cadastra duas cartas com dados de cidades e escolhe dois atributos para comparação. O sistema calcula automaticamente os valores e determina o vencedor da rodada.

Projeto desenvolvido com foco em aprendizado de:

Estruturas (struct)

Funções

Operadores condicionais

Menu dinâmico

Operador ternário

Cálculos matemáticos

🚀 Funcionalidades

Cadastro de duas cartas

Cálculo automático de:

Densidade demográfica

PIB per capita

Super Poder

Menu dinâmico de escolha de atributos

Comparação de dois atributos por rodada

Regra especial para densidade demográfica

Exibição do vencedor da rodada

Tratamento básico de erro (validação de opções)

🛠 Tecnologias Utilizadas

Linguagem C

Biblioteca padrão <stdio.h>

📊 Estrutura da Carta

Cada carta contém:

Atributo	Tipo
Estado	char
Código	char[5]
Nome da Cidade	char[50]
População	unsigned long int
Área	float
PIB	float
Pontos Turísticos	int
Densidade	float
PIB per Capita	float
Super Poder	float
🧠 Regras do Jogo

O jogador escolhe dois atributos diferentes para comparação:

População

Área

PIB

Pontos Turísticos

Densidade Demográfica

🔎 Regra especial:

Para Densidade Demográfica, vence quem tiver MENOR densidade.

O código trata isso invertendo o valor antes da soma.

🏆 Vence quem tiver a maior soma dos dois atributos escolhidos.

💻 Como Compilar e Executar
🔹 Usando GCC
gcc super_trunfo.c -o super_trunfo
./super_trunfo

🔹 No Windows (MinGW)
gcc super_trunfo.c -o super_trunfo.exe
super_trunfo.exe

📂 Estrutura do Projeto
📁 super-trunfo/
 ├── super_trunfo.c
 └── README.md
 
🧮 Fórmulas Utilizadas
📌 Densidade Demográfica
densidade = população / área
📌 PIB per Capita
pibPerCapita = pib / população
📌 Super Poder
superPoder = população + área + pib + pontos turísticos + pib per capita + (1 / densidade)
🎯 Objetivo do Projeto

Projeto acadêmico com foco em prática de:

Estruturas em C

Modularização com funções

Lógica condicional

Manipulação de entrada do usuário

Comparações numéricas

Operador ternário

Desenvolvido por Hailan
