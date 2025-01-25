# Gerenciador Financeiro

### [Vídeo](https://youtu.be/KZvzo8PATW0)
### **Descrição**

O **Gerenciador Financeiro** é um programa desenvolvido em Python que permite aos usuários monitorar suas finanças de forma simples e eficiente diretamente no terminal. Ele foi projetado para organizar receitas e despesas, exibir transações em períodos específicos e fornecer um resumo financeiro claro com receitas totais, despesas totais e saldo atual.

---

### **Funcionalidades**

1. **Adicionar Transação**  
   Os usuários podem registrar novas transações, indicando o tipo (receita ou despesa), categoria, valor e descrição. Todas as transações são salvas em um arquivo JSON para persistência de dados.

2. **Listar Transações**  
   O programa exibe todas as transações registradas, com a possibilidade de aplicar filtros de data para facilitar a análise.

3. **Resumo Financeiro**  
   Apresenta um resumo detalhado das finanças do usuário, incluindo:
   - Total de receitas
   - Total de despesas
   - Saldo atual (receitas - despesas)

4. **Filtragem por Data**  
   Os usuários podem filtrar transações ou resumos financeiros por um intervalo de datas específico.

5. **Persistência de Dados**  
   Todas as informações são armazenadas em um arquivo `transacoes.json`, garantindo que os dados permaneçam disponíveis entre execuções do programa.

---

### **Arquivos do Projeto**

#### **1. `main.py`**  
Arquivo principal que executa o programa e gerencia a interação com o usuário. Contém:
   - Menu principal com opções de navegação.
   - Funções auxiliares para entrada e validação de dados.
   - Integração com as funções de gerenciamento de transações definidas em `transaction.py`.

#### **2. `transaction.py`**  
Módulo responsável pelo gerenciamento de transações. Contém:
   - Função para adicionar novas transações (`adicionar_transacao`).
   - Função para listar transações existentes (`listar_transacoes`).
   - Função para filtrar transações por intervalo de datas (`filtrar_por_data`).
   - Função para calcular o resumo financeiro (`calcular_resumo`).
   - Funções para salvar e carregar dados no arquivo `transacoes.json`.

#### **3. `transacoes.json`**  
Arquivo de armazenamento que contém todas as transações registradas em formato JSON. Ele é automaticamente criado e atualizado pelo programa conforme as transações são adicionadas ou manipuladas.

---

### **Como Executar o Programa**

1. Certifique-se de ter o Python 3 instalado em seu sistema.
2. Baixe ou clone este repositório.
3. Execute o programa no terminal usando:

   ```bash
   python main.py

--- 

### **Possíveis Expansões**

Este projeto foi desenvolvido com expansões futuras em mente. Algumas ideias incluem:

1. **Gráficos e Visualizações**: Integração com bibliotecas como `matplotlib` ou `seaborn` para criar gráficos de receitas e despesas.

2. **Interface Gráfica para o Usuário (GUI)**: Utilizando bibliotecas como `Tkinter` ou `Kivy`, seria possível criar uma interface intuitiva que permita ao usuário navegar por menus, adicionar transações e visualizar resumos financeiros sem precisar interagir diretamente com o terminal.

3. **Integração com Banco de Dados**: Migração dos dados para um banco de dados relacional (como SQLite) ou não-relacional (como MongoDB) para maior escalabilidade.

4. **Relatórios Avançados**: Geração automática de relatórios financeiros em formato PDF ou Excel.

5. **Sistema de Notificações**: Alertas para despesas excessivas ou metas financeiras não atingidas.

6. **Sistema de Múltiplos Usuários**: Adicionar suporte para múltiplos usuários permitiria que o programa fosse utilizado por diferentes pessoas no mesmo dispositivo, ou até mesmo de forma compartilhada em uma rede. Cada usuário teria seu próprio perfil, com transações e resumos financeiros armazenados separadamente.
