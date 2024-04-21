import java.io.*;
import java.util.*;

class ExternalSort {
    private static final int chunkSize = 1024;
    private static final int ram = 3;// assumed internal memory size accepting 30 lines from input line created near
                                     // xamppath in my case

    public void externalSort(String inputFile, String OutputFile) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader(inputFile));
        // herer i have created two file readers because of parellel processing just an
        // approach to simply further merge process while sorting an balenced
        // distribution
        BufferedWriter writer1 = new BufferedWriter(new FileWriter("output1.temp"));// after writing this writer file
                                                                                    // created automatically
        BufferedWriter writer2 = new BufferedWriter(new FileWriter("output2.temp"));
        List<String> buffer = new ArrayList<>(ram);// used as physical processing perrformer in m csase inatialized as
                                                   // of isze ram

        // sample phases for distribution in output filewriter files
        int phase = 0;
        String lineReader;
        if (reader.ready()) {
            while ((lineReader = reader.readLine()) != null) {
                // System.out.println(lineReader);
                buffer.add(lineReader);// here i added line as an string teturn valus getted from linereader
                if (buffer.size() >= ram) {
                    System.out.println("Ram is full cannot accept nore data...");
                    Collections.sort(buffer);// here i have sorted arriven buffer as ram get full
                    // for parellel balenced data sending in file
                    if (phase % 2 == 0) {
                        writeToTape(buffer, writer1);
                    } else {
                        writeToTape(buffer, writer2);
                    }
                    phase += 1;
                    buffer.clear();// clearing ram as arriven data has been processed and ram is accepting next
                                   // data
                }
            }
            // at end if ram not full but data still present in ram in minimum amount that
            // must be sent to tape
            if (!buffer.isEmpty()) {
                System.out.println("buffer has still some data...");
                if (phase % 2 == 0) {
                    writeToTape(buffer, writer1);
                } else {
                    writeToTape(buffer, writer2);
                }
                buffer.clear();// clearing ram as rams task has been over freeing for optimizing  other tasks
                phase++;//increaese phase count for accomodation
            }
            //closing tapes as an good practice
            reader.close();
            writer1.close();
            writer2.close();
        }
    }

    private void writeToTape(List<String> buffer, BufferedWriter tape) throws IOException {
        System.out.println("data arriven for writing purpose...");
        for (String line : buffer) {
            tape.write(line);
            tape.newLine();
        }
    }

    private void mergeSortedTapes(){
        
    }

    public static void main(String[] arg) throws IOException {
        System.out.println("hello");
        String inputFile = "input.txt";
        String outputFile = "output.txt";
        ExternalSort sort = new ExternalSort();
        sort.externalSort(inputFile, outputFile);

    }
}