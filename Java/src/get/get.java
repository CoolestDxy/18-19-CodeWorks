package get;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

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
			File file = new File("E:tst.log");
			get a = new get(file);
			a.write(97);
			a.write('b');
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
		}
	}
}
