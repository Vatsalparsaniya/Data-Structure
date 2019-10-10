//This program does image edge detection in java 

import java.io.File;
import java.awt.Color;
import java.io.IOException;
import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;
public class Hsegmentation
{   
    static BufferedImage image = null;
    public static void main()throws IOException
    {
        int red1,red2,green1,green2,blue1,blue2,avg1,avg2,a=0,boundary,count=0;
        try
        {
        File input_file = new File("Images\\Altaha1.jpg"); //Add address of image file  
        image = ImageIO.read(input_file);
        System.out.println("Reading complete. ");
        int y= image.getHeight();
        int x= image.getWidth();
        int i,j,c=21;
        for(i=0; i<y; i++)
        {  int max=0;
        for(int k=0; k<2; k++)
        
        for(j=0; j<(x-1); j++)
        {
        Color c1 = new Color(image.getRGB(j,i));
        Color c2 = new Color(image.getRGB(j+1,i));
        red1 = (int)(c1.getRed());
        blue1 = (int)(c1.getBlue());
        green1 = (int)(c1.getGreen());
        avg1=  (red1+green1+blue1)/3;
        red2 = (int)(c2.getRed());
        blue2 = (int)(c2.getBlue());
        green2 = (int)(c2.getGreen());
        avg2=  (red2+green2+blue2)/3;
        int diff = Math.abs(avg2-avg1);
        if(diff>max)
        {max= diff;
        }
        if(max-diff<=c && k==1)
        { 
          boundary= j - a;
          if(boundary>=4 || j<4)
          {Color cn = new Color(0,255,0);
           image.setRGB(j,i,cn.getRGB());}
          a = j;
          count++;
        }

    }
    }
    System.out.println(count); //Prints number of pixel changes
    File output = new File("Images\\grey.jpg");
    ImageIO.write(image,"jpg",output);
}   catch(Exception e){
            e.printStackTrace();}
    }
}
