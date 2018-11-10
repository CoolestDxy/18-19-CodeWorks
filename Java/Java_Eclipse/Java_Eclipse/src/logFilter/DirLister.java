package logFilter;

import java.io.File;
import java.io.FilenameFilter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

/**
 * @package logFilter
 * @description ÁÐ³öÄ¿Â¼
 * @author Hanyuu
 * @date 2018/11/09
 */
public class DirLister {

	/**
	 * @param file
	 * @param filter
	 * @param comparator
	 * @author Hanyuu
	 * @date 2018/11/09
	 */
	public void listDirectory(/* File file, */ FilenameFilter filter, Comparator comparator) {
		// 用户输入命令行
		Scanner input = new Scanner(System.in);
		System.out.println("Please input your filefolder name:");
		String fileName = input.nextLine();
		File file = new File(fileName);
		if (!file.exists()) {
			System.out.println("Path error");
		} else if (file.isFile()) {
			System.out.println("Not a directory");
		} else {
			File[] files = file.listFiles(filter);
			System.out.println("File list length:" + Integer.toString(files.length));
			Arrays.sort(files, comparator);
			for (int i = 0; i < files.length; ++i) {
				if (files[i].isFile()) {
					System.out.println(files[i]);
				}
			}
		}
	}

	/**
	 * @param args
	 * @author Hanyuu
	 * @date 2018/11/09
	 */
	public static void main(String[] args) {
		DirLister lister = new DirLister();
		DirFilter filter = new DirFilter(".+log");
		lister.listDirectory(/* new File("c:/Windows"), */filter, new DescendingAlphabeticComparator());
	}
}
