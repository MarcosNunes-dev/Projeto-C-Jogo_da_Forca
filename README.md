# Projeto Jogo da Forca - Linguagem C 

Este é um clássico Jogo da Forca desenvolvido em C, estruturado de forma modular para demonstrar boas práticas de programação, como o uso de headers e prototipagem de funções.

## 🛠️ Funcionalidades

- **Lógica de Jogo:** Verificação de acertos, erros e controle de tentativas.
- **Estrutura Modular:** Código dividido para facilitar a leitura e manutenção.
- **Prototipagem:** Definição clara das funções em arquivo de cabeçalho.
- **Interface via Terminal:** Interação direta e simples com o usuário.

## 📁 Estrutura do Projeto

O projeto utiliza a separação de responsabilidades entre arquivos:

* **`jogo.h` (Header File):** Contém a **prototipagem** de todas as funções e as definições de constantes. Ele serve como o "manual" do que o programa é capaz de fazer.
* **`jogo.c`:** Implementação das funções e toda a lógica de funcionamento do jogo.
* **`projetoFinal.c`:** Ponto de entrada do programa (contém a função `main`) que coordena a execução utilizando as funções prototipadas.

## 🚀 Como Compilar e Executar

Como o projeto é modular, é necessário compilar os arquivos `.c` juntos:

```bash
# Compilação dos módulos
gcc jogo.c projetoFinal.c -o forca

# Execução
./forca
