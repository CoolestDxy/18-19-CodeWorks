package BM;

import java.io.*;
import java.nio.Buffer;
import java.util.ArrayList;

public class BufferTest {
	private ArrayList<Integer> intStoreSource;
	private ArrayList<Integer> intStoreTarget;
	private final int MAX_STORE_SIZE = 500000;
	private File file;

	public static int getRandomInt() {
		return (int) (Math.random() * 255);
	}

	private void buildIntStore() {
		for (int i = 0; i < MAX_STORE_SIZE; i++) {
			intStoreSource.add(getRandomInt());
		}
	}

	public BufferTest(File file) {
		this.intStoreSource = new ArrayList<Integer>();
		this.intStoreTarget = new ArrayList<Integer>();
		this.buildIntStore();
		this.file = file;
	}

	private void useFileInputStream() throws IOException {
		FileInputStream fis = new FileInputStream(this.file);
		int intValue = fis.read();
		while (intValue != -1) {
			this.intStoreTarget.add(intValue);
			intValue = fis.read();
		}
		fis.close();
	}

	private void useFileOutputStream() throws IOException {
		FileOutputStream fos = new FileOutputStream(this.file);
		for (int i = 0; i < this.intStoreSource.size(); i++) {
			fos.write(intStoreSource.get(i));
		}
		fos.close();
	}

	private void useBufferedInputStream() throws IOException {
		BufferedInputStream bis = new BufferedInputStream(new FileInputStream(this.file));
		int intValue = bis.read();
		while (intValue != -1) {
			this.intStoreTarget.add(intValue);
			intValue = bis.read();
		}
		bis.close();
	}

	private void useBufferedOutputStream() throws IOException {
		BufferedOutputStream bos = new BufferedOutputStream(new FileOutputStream(this.file));
		for (int i = 0; i < this.intStoreSource.size(); i++) {
			bos.write(intStoreSource.get(i));
		}
		bos.close();
	}

	private void test() throws IOException {
		System.gc();
		long time1 = System.currentTimeMillis();
		this.useFileOutputStream();
		long time2 = System.currentTimeMillis();
		this.useFileInputStream();
		long time3 = System.currentTimeMillis();

		this.intStoreTarget = new ArrayList<Integer>();
		System.gc();
		long time4 = System.currentTimeMillis();
		this.useBufferedOutputStream();
		long time5 = System.currentTimeMillis();
		this.useBufferedInputStream();
		long time6 = System.currentTimeMillis();
		System.out.println("FileOutputStream:" + (time2 - time1));
		System.out.println("FileInputStream:"+(time3-time2));
		System.out.println("BufferedOutputStream:" + (time5 - time4));
		System.out.println("BufferedInputStream:"+(time6-time5));
	}

	public static void main(String[] args) {
		BufferTest test=new BufferTest(new File("E:/brenchMark.dat"));
		try{
			test.test();

		}catch (Exception e){
			e.printStackTrace();;
		}
	}
}
