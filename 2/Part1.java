package Day2;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;

public class Part1 {
    public static void main(String[] args) throws IOException {
        String filepath = "input.txt";

        Path path = Paths.get(filepath);

        List<String> lines = Files.readAllLines(path);

        int sum = 0;

        for (String line : lines) {
            String gameId = line.substring(5).split(":")[0];
            String[] games = line.split(":")[1].split(";");
            boolean valid = true;
            for (String game : games) {
                String[] values = game.split(",");
                for (String value : values) {
                    int i = Integer.parseInt( value.substring(1).split(" ")[0]);
                    String color = value.substring(1).split(" ")[1];
                    if (color.equals("red") && i > 12) {
                        valid = false;
                    }else if (color.equals("green") && i>13) {
                        valid = false;
                    }else if (color.equals("blue") && i>14) {
                        valid = false;
                    }
                }
            }
            if (valid) {
                sum += Integer.parseInt(gameId);
            }
        }

        System.out.println(sum);


    }
}