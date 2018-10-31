package BM;

import java.io.IOException;
import java.io.RandomAccessFile;
import java.nio.MappedByteBuffer;
import java.nio.channels.FileChannel;

public class nio {
	static int length = 0xfffffff;
	public static void main(String[] args)throws IOException {
		MappedByteBuffer out=new RandomAccessFile("E:/nio.log","rw").getChannel().map(FileChannel.MapMode.READ_WRITE,0 ,length);
		long begin=System.currentTimeMillis();
		for (int i=0;i<length;i++){
			out.put((byte)'C');
		}
		long end=System.currentTimeMillis();
		System.out.println((end-begin)+"ms");
		for (int i=length/2;i<length/2+6;i++)
		{
			System.out.print((char)out.get(i));
		}
	}
}
