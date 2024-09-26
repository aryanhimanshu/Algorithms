public static void main(String[] args) {
    int[] data = {6,3,17,8,4,7,2,28};
    int tampung = 0;
    for (int x = 0; x < data.length; x++) {
        for (int y = x + 1; y < data.length; y++) {
            System.out.println("\nmembandingkan "+data [x] + " dengan " + data[y]);
            System.out.print("awalnya data[x] adalah" + data[x] + "lalu");
                
            if (data[x] > data[y]) {
                tampung = data[x];
                data[x] = data[y];
                data[y] = tampung;
                System.out.print("data[x] menjadi " + data[x] +", data[y] menjadi " + data[y] +"."); 
            }
            else{
                System.out.print("data[x] tidak ditukar karena tidak memenuhi kondisi if dan data[y] berlanjut");
            }
        }   
    }
}
