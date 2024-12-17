public class App {
    public static void main(String[] args) throws Exception {
        Celular celularA = new Celular();
        celularA.nome = "Iphone 12";
        celularA.tamanhoTela = 6.1f;
        celularA.espacoArmazenamento = 256;
        celularA.sistemaOperacaional = "iOS";

        System.out.format("Celular %s com tela de %.1f, com %dgb e SO %s\n", 
            celularA.nome, celularA.tamanhoTela, celularA.espacoArmazenamento, celularA.sistemaOperacaional);
    }
}