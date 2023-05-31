//bibliotecas
import java.util.Scanner;
import java.net.Socket;

//Classe com extensao da classe Thread responsavel por tratar as mensagens do cliente
public class AtendeCliente extends Thread {
    
    //Atributos
    Socket client;

    //Construtor
    AtendeCliente(Socket serverSocket){
        this.client = serverSocket;
    }

    //metodo run
    @Override
    public void run() {
            try {
                Scanner entrada = new Scanner(this.client.getInputStream());
                while (entrada.hasNextLine()) {
                    String msg = entrada.nextLine();
                    System.out.println(msg);
                    ChatServer.enviaMenssagem(msg , client);
                }            
            }catch (Exception e) {
               System.out.println("Nao foi possivel ler mensagens: " + e.getMessage());
            }
        super.run();
    }
}
