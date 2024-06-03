# Agenda de Lembretes e Calendário Acadêmico

## Descrição

Este projeto é uma aplicação de linha de comando em C que permite aos usuários gerenciar lembretes e visualizar um calendário acadêmico. A aplicação oferece funcionalidades para criar, visualizar e excluir lembretes, bem como um calendário acadêmico detalhado e interativo.

## Funcionalidades

1. **Gestão de Lembretes**:
    - **Criar Lembretes**: Permite ao usuário criar novos lembretes.
    - **Visualizar Lembretes**: Exibe os lembretes existentes.
    - **Excluir Lembretes**: Permite ao usuário excluir lembretes.

2. **Calendário Acadêmico**:
    - **Visualizar Calendário**: Exibe um calendário interativo que permite navegação entre dias e meses.
    - **Calendário Acadêmico da Turma ADA**: Exibe o calendário acadêmico específico da turma de Engenharia de Software.

3. **Outras Funcionalidades**:
    - **Créditos dos Desenvolvedores**: Exibe os créditos dos desenvolvedores do projeto.
    - **Saída Animada**: Exibe uma animação de saída com um carro ASCII art.

## Estrutura do Projeto

- `main.c`: Arquivo principal que contém a lógica de inicialização e o loop principal da aplicação.
- `funcoes.h`: Cabeçalhos das funções auxiliares.
- `funcoes.c`: Implementações das funções auxiliares.
- `logo.h`: Cabeçalhos das funções que desenham os logotipos e animações.

## Como Executar

1. Clone este repositório:
    ```bash
    git clone <URL_do_repositório>
    ```

2. Navegue até o diretório do projeto:
    ```bash
    cd <nome_do_diretório>
    ```

3. Compile o código:
    ```bash
    gcc main.c funcoes.c -o agenda
    ```

4. Execute a aplicação:
    ```bash
    ./agenda
    ```

## Uso

Após executar a aplicação, o usuário será apresentado com um menu principal com as seguintes opções:

1. **Lembretes**:
    - Criar, visualizar e excluir lembretes.

2. **Calendário**:
    - Visualizar e navegar no calendário.
    - Acessar o calendário acadêmico da turma ADA.

3. **Créditos dos Desenvolvedores**:
    - Exibir os créditos dos desenvolvedores do projeto.

4. **Sair**:
    - Exibir a animação de saída e encerrar a aplicação.

### Navegação no Calendário

- `a`: Dia anterior
- `d`: Próximo dia
- `w`: Mês anterior
- `s`: Próximo mês

## Desenvolvedores

<table>
  <tr>
    <td align="center"><a href="https://github.com/Adryanrr"><img src="https://github.com/Adryanrr.png" width="100px;" alt="Foto do Adryan Ryan"/><br /><sub><b>Adryan Ryan</b></sub></a></td>
    <td align="center"><a href="https://github.com/Whuanderson/whuanderson"><img src="https://avatars.githubusercontent.com/u/83825566?v=4" width="100px;" alt="Foto do Whuanderson Marinho"/><br /><sub><b>Whuanderson Marinho</b></sub></a></td>
    <td align="center"><a href="https://github.com/MatheusJuK"><img src="https://github.com/MatheusJuK.png" width="100px;" alt="Foto do Matheus Juca"/><br /><sub><b>Matheus Juca</b></sub></a></td>
    <td align="center"><a href="https://github.com/AndreNTeixeira"><img src="https://github.com/AndreNTeixeira.png" width="100px;" alt="Foto do Andre Texeira"/><br /><sub><b>Andre Texeira</b></sub></a></td>
  </tr>
</table>

## Licença

Este projeto está licenciado sob a [MIT License](LICENSE).

---