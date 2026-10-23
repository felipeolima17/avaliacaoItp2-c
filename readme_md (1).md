# Sistema de Boletim Escolar (Matrizes de Notas)

## 1. Identificacao

* **Estudante:** Felipe Oliveira Bittencourt Lima

* **Opcao de Projeto:** Matrizes de notas de uma turma pequena

## 2. Descricao do Projeto

O programa resolve o problema de consolidacao, calculo e exibicao do desempenho academico de uma turma de pequeno porte (ate 10 estudantes). Ele automatiza a leitura de notas, calcula as medias individuais e gerais, e classifica os estudantes de acordo com o atingimento da meta escolar.

### Funcionalidades Implementadas

* **Validacao de Entrada:** Impede o cadastro de numero de alunos fora do intervalo de 1 a 10 e rejeita notas fora da faixa de 0.0 a 10.0 ou valores nao numericos.

* **Sanitizacao de Buffer de Teclado:** Tratamento de residuos do scanf com `getchar()` e remocao do caractere de quebra de linha (`\n`) capturado pelo `fgets` no nome do estudante.

* **Estrutura de Dados em Matrizes:** Matriz `char` para armazenamento de strings com os nomes dos estudantes e matriz `float` para armazenamento das notas individuais.

* **Alocacao Dinamica de Memoria:** Uso da funcao `calloc` para reservar o vetor de medias no Heap conforme a quantidade de alunos informada, incluindo verificacao de falha de alocacao (`NULL`) e liberacao de memoria com `free()`.

* **Calculo e Processamento de Dados:** Calculo das medias via ponteiros, calculo da media geral da sala e identificacao do estudante com a maior nota (com suporte a empates).

* **Exibicao Formatada:** Apresentacao dos dados em formato de tabela organizada com indicacao da situacao ("Atingiu a meta" para media maior ou igual a 6.0 e "Abaixo da meta" para media menor que 6.0).

## 3. Compilacao e Execucao

Para compilar e executar o codigo fonte (assumindo o arquivo nomeado como `main.c`), utilize um terminal com o compilador GCC instalado:

### Compilacao

```
gcc -std=c11 -Wall -Wextra main.c -o programa

```

### Execucao

```
./programa

```

## 4. Testes Realizados

### Teste 1: Funcionamento Normal

Entrada regular com 2 estudantes e dados validos.

**Entradas inseridas:**

* Quantidade de estudantes: `2`

* Estudante 1: `Ana Silva` | Notas: `8.0`, `7.5`, `9.0`

* Estudante 2: `Bruno Souza` | Notas: `5.0`, `4.0`, `6.0`

**Resultado Esperado:**

```
===============================================================================
Estudante            | Nota 1 | Nota 2 | Nota 3 | Media  | Situacao       
===============================================================================
Ana Silva            |   8.00 |   7.50 |   9.00 |   8.17 | Atingiu a meta 
Bruno Souza          |   5.00 |   4.00 |   6.00 |   5.00 | Abaixo da meta 
===============================================================================

Media geral da turma: 6.58
Estudante(s) com a maior media (8.17):
- Ana Silva

```

### Teste 2: Entradas Invalidas e Limites

Validacao de comportamento diante de dados incorretos e teste do limite inferior de alunos (1).

**Entradas inseridas:**

* Quantidade de estudantes: `15` (invalido) -> `-1` (invalido) -> `1` (valido)

* Nome do Estudante 1: entrada vazia (invalido) -> `Carlos Lima` (valido)

* Nota 1: `12.0` (invalida) -> `10.0` (limite superior valido)

* Nota 2: `-2.0` (invalida) -> `abc` (texto invalido) -> `6.0` (valido)

* Nota 3: `8.0` (valido)

**Resultado Esperado:**

O programa exibe mensagens de erro especificas para cada entrada incorreta ate que um valor valido seja fornecido:

```
Quantidade invalida! Por favor, insira um valor entre 1 e 10.
Quantidade invalida! Por favor, insira um valor entre 1 e 10.
--- Cadastro do Estudante 1 de 1 ---
Digite o nome do estudante: 
Erro: O nome nao pode ser vazio. Tente novamente.
Digite o nome do estudante: Carlos Lima
Digite a 1ª nota (0.0 a 10.0): 12.0
Nota invalida! O valor deve estar no intervalo de 0.0 a 10.0.
Digite a 1ª nota (0.0 a 10.0): 10.0
Digite a 2ª nota (0.0 a 10.0): -2.0
Nota invalida! O valor deve estar no intervalo de 0.0 a 10.0.
Digite a 2ª nota (0.0 a 10.0): abc
Entrada invalida! Digite um numero decimal.
Digite a 2ª nota (0.0 a 10.0): 6.0
Digite a 3ª nota (0.0 a 10.0): 8.0

===============================================================================
Estudante            | Nota 1 | Nota 2 | Nota 3 | Media  | Situacao       
===============================================================================
Carlos Lima          |  10.00 |   6.00 |   8.00 |   8.00 | Atingiu a meta 
===============================================================================

Media geral da turma: 8.00
Estudante(s) com a maior media (8.00):
- Carlos Lima

```

## 5. Video de Apresentacao

* [Clique aqui para assistir a apresentacao do codigo no YouTube](https://youtu.be/DFQ77KquIj8)

## 6. Referencias

* Videos e materiais didaticos das disciplinas disponibilizados na plataforma SIGAA.

* Gemini AI: Suporte tecnico no esclarecimento do tratamento de buffers de entrada em C (`getchar`, `fgets`) e na estruturacao da documentacao.