# avaliacao Itp unidade 2

# Sistema de Boletim Escolar (Matrizes de Notas)

## 1. Identificação
* **Estudante:** Felipe Oliveira Bittencourt Lima
* **Opção de Projeto:** Matrizes de notas de uma turma pequena

---

## 2. Descrição do Projeto
O programa resolve o problema de consolidação, cálculo e exibição do desempenho acadêmico de uma turma de pequeno porte (até 10 estudantes). Ele automatiza a leitura de notas, calcula as médias individuais e gerais, e classifica os estudantes de acordo com o atingimento da meta escolar.

### Funcionalidades Implementadas
* **Validação de Entrada:** Impede o cadastro de número de alunos fora do intervalo [1, 10] e rejeita notas fora da faixa de 0.0 a 10.0 ou valores não numéricos.
* **Sanitização de Buffer de Teclado:** Tratamento de resíduos do `scanf` com `getchar()` e remoção do caractere de quebra de linha (`\n`) capturado pelo `fgets` no nome do estudante.
* **Estrutura de Dados em Matrizes:**
  * Matriz `char` para armazenamento de strings com os nomes dos estudantes.
  * Matriz `float` para armazenamento das notas individuais de cada estudante.
* **Alocação Dinâmica de Memória:** Uso da função `calloc` para reservar o vetor de médias no Heap conforme a quantidade de alunos informada, incluindo verificação de falha de alocação (`NULL`) e liberação de memória com `free()`.
* **Cálculo e Processamento de Dados:** Cálculo das médias via ponteiros, cálculo da média geral da sala e identificação do(s) estudante(s) com a maior nota (com suporte a empates).
* **Exibição Formatada:** Apresentação dos dados em formato de tabela organizada com indicação da situação ("Atingiu a meta" para média >= 6.0 "Abaixo da meta" para média < 6.0).

---

## 3. Compilação e Execução

Para compilar e executar o código fonte (assumindo o arquivo nomeado como `main.c`), utilize um terminal com o compilador GCC instalado:

### Compilação
```bash
gcc -std=c11 -Wall -Wextra main.c -o programa

execução:
./programa


Testes Realizados
Teste 1: Funcionamento Normal
Entrada regular com 2 estudantes e dados válidos.

Entradas inseridas:

Quantidade de estudantes: 2

Estudante 1: Ana Silva | Notas: 8.0, 7.5, 9.0

Estudante 2: Bruno Souza | Notas: 5.0, 4.0, 6.0

Resultado Esperado:
===============================================================================
Estudante            | Nota 1 | Nota 2 | Nota 3 | Media  | Situacao       
===============================================================================
Ana Silva            |   8.00 |   7.50 |   9.00 |   8.17 | Atingiu a meta 
Bruno Souza          |   5.00 |   4.00 |   6.00 |   5.00 | Abaixo da meta 
===============================================================================

Media geral da turma: 6.58
Estudante(s) com a maior media (8.17):
- Ana Silva


