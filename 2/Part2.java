package Day2;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;

public class Part2 {
    public static void main(String[] args) throws IOException {
        String filepath = "input.txt";

        Path path = Paths.get(filepath);

        List<String> lines = Files.readAllLines(path);

        int sum = 0;

        for (String line : lines) {
            String gameId = line.substring(5).split(":")[0];
            String[] games = line.split(":")[1].split(";");
            int red = 0;
            int blue = 0;
            int green = 0;
            for (String game : games) {
                String[] values = game.split(",");
                for (String value : values) {
                    int i = Integer.parseInt( value.substring(1).split(" ")[0]);
                    String color = value.substring(1).split(" ")[1];
                    if (color.equals("red") && i > red) {
                        red = i;
                    }else if (color.equals("green") && i>green) {
                        green = i;
                    }else if (color.equals("blue") && i>blue) {
                        blue = i;
                    }
                }
            }
            sum += red * blue * green;

        }

        System.out.println(sum);


    }
}