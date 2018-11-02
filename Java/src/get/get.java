package get;

import java.io.*;

public class get {
	private FileInputStream fis;
	private FileOutputStream fos;

	public get(File file) throws IOException {
		createFile(file);
		this.fis = new FileInputStream(file);
		this.fos = new FileOutputStream(file);
	}

	public static void createFile(File file) throws IOException {
		if (!file.exists() || !file.isFile()) {
			file.createNewFile();
		}
	}

	public void close() throws IOException {
		fis.close();
		fos.close();
	}

	public int read() throws IOException {
		return fis.read();
	}

	public void write(int arg) throws IOException {
		fos.write(arg);
	}

	public void write(byte[] arg) throws IOException {
		fos.write(arg);
	}

	public int available() throws IOException {
		return fis.available();
	}

	public static void main(String[] args) {

		try {
			FileWriter fw=new FileWriter("E:/a.log");
			fw.write("市附近的路口附近".toCharArray());
			fw.flush();
			fw.write(-1);
			fw.write('A');
			fw.close();
			FileReader fr=new FileReader("E:/a.log");
			int ch=fr.read();
			while (ch!=-1)
			{
				System.out.print((char)ch);
				ch=fr.read();
			}

			File file = new File("E:/tst.log");
			get a = new get(file);
			a.write(97);
			a.write('b');
			a.write(260);
			a.write(305);
			a.write(new String("哈").getBytes());
			System.out.println(a.available()+"size");
			int i=a.read();
			while (i!=-1){
				System.out.println((char)i);
				i=a.read();
			}
			a.close();

		} catch (Exception e) {
			System.out.println(e);
			e.printStackTrace();
		}
	}
}
//DataInputStream
//DataOutputStream