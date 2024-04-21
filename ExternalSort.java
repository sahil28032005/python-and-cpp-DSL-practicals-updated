import java.io.*;
import java.util.*;

class ExternalSort {
    private static final int chunkSize = 1024;
    private static final int ram = 4;// assumed internal memory size accepting 30 lines from input line created near
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
                buffer.clear();// clearing ram as rams task has been over freeing for optimizing other tasks
                phase++;// increaese phase count for accomodation
            }
            // closing tapes as an good practice
            reader.close();
            writer1.close();
            writer2.close();

            //sending tapes to merge
            mergeSortedTapes("output1.temp","output2.temp", OutputFile);
        }
    }

    private void writeToTape(List<String> buffer, BufferedWriter tape) throws IOException {
        System.out.println("data arriven for writing purpose...");
        for (String line : buffer) {
            tape.write(line);
            tape.newLine();
        }
    }

    private void mergeSortedTapes(String tape1, String tape2, String outputTape) throws IOException {
        // in this phase we just merge splitted data from our file in single output
        // driver file
        // creating readers and writers for our files
        BufferedReader reader1 = new BufferedReader(new FileReader(tape1));// tape 1 reader
        BufferedReader reader2 = new BufferedReader(new FileReader(tape2));// tae 2 reader
        // ccreating writer for output file
        BufferedWriter writer = new BufferedWriter(new FileWriter(outputTape));
        // taking lines from tapes and comparing them to send to output file
        String line1 = reader1.readLine();
        String line2 = reader2.readLine();

        while (line1 != null && line2 != null) {
            if (line1.compareTo(line2) <= 0) {
                // meanse line 1 consists smaller data
                writer.write(line1);
                writer.newLine();
                line1 = reader1.readLine();// to go next line in further iterations
            } else {
                writer.write(line2);
                writer.newLine();
                line2 = reader2.readLine();// move cursor to next for further iterations
            }
        }
        // checking if some input data still rmaining in case of one tape is empty
        while (line1 != null) {
            // means line 1 tape has some data remaining
            writer.write(line1);
            writer.newLine();
            line1 = reader1.readLine();
        }
        while (line2 != null) {
            writer.write(line2);
            writer.newLine();
            line2 = reader2.readLine();
        }
        // closing tapes as an good practic
        reader1.close();
        reader2.close();
        writer.close();

    }

    public static void main(String[] arg) throws IOException {
        System.out.println("hello");
        String inputFile = "input.txt";
        String outputFile = "output.txt";
        ExternalSort sort = new ExternalSort();
        sort.externalSort(inputFile, outputFile);

    }
}