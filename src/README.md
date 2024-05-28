# Projeto Calendário em C

Este é um projeto desenvolvido para a faculdade que consiste em um calendário com funcionalidades adicionais como visualização de lembretes e calendário acadêmico. O projeto é implementado em C e utiliza funções básicas para interagir com o usuário através do terminal.

## Funcionalidades

- **Visualização de Calendário**
- **Visualização de Lembretes**
- **Criação de Lembretes**
- **Visualização de Calendário Acadêmico**

## Estrutura do Código

### Arquivos

- `main.c`: Contém todas as funções necessárias para o funcionamento do calendário.

## Como Compilar e Executar

1. **Compilar o código**: Use um compilador C como `gcc`.
    ```sh
    gcc main.c -o calendario
    ```
2. **Executar o programa**:
    ```sh
    ./calendario
    ```

## Menu Principal

Ao iniciar o programa, o usuário verá o seguinte menu:

```
+===================================================================+
|         1 - Calendario              3 - Calendario Academico      |
+===================================================================+
|    2 - Visualizar Lembretes                 4 - Exit              |
+===================================================================+
Digite Qual opção você deseja acessar: 
```

### Opções do Menu

- **1 - Calendário**: Direciona para a visualização do calendário.
- **2 - Visualizar Lembretes**: Direciona para a seção de visualização de lembretes (em construção).
- **3 - Calendário Acadêmico**: Mostra a grade horária do calendário acadêmico.
- **4 - Sair**: Encerra o programa.

## Estrutura das Funções

### `limparTerminal()`

Limpa a tela do terminal, funcionando tanto para Windows quanto para sistemas Unix-like.

### `MenuPrincipal()`

Exibe o menu principal e direciona o usuário para a funcionalidade escolhida.

### `VisualizarCalendario()`

Permite ao usuário visualizar outro mês ou criar um lembrete.

### `visualizarLembretes()`

Função em construção que futuramente permitirá visualizar lembretes.

### `calendarioIcev()`

Exibe o calendário acadêmico com horários de aulas e outras atividades.

### `CriarLembretes()`

Permite ao usuário criar novos lembretes, solicitando hora e descrição.

### `TrocaMes()`

Função em construção para permitir a troca de mês no calendário.

## Observações

- Algumas funções estão marcadas como "Em construção" e serão desenvolvidas futuramente.
- O programa está preparado para ser expandido com novas funcionalidades conforme necessário.

## Desenvolvedores
@adryanrr
@whuanderson.marinho
@matheusJuca
@andre.texeira
