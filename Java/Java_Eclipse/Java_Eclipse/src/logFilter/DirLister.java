package logFilter;

import java.io.File;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;
import java.util.Date;

/**
 * @package logFilter
 * @description 文件筛选器
 * @author Hanyuu
 * @date 2018/11/09
 */
/**
 * @typename DirLister
 * @package logFilter
 * @description DirLister
 * @author Hanyuu
 * @date 2018/11/11
 * @TODO TODO
 */
public class DirLister {
	private DirFilter filter;
	private HanyuuFileComparator comparator;


	public void listDirectory(/* File file, FilenameFilter filter, Comparator comparator */) {
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
			System.out.println("Please input what suffix you want to search:");
			String suffix;
			suffix = input.next();
			filter = new DirFilter(".+" + suffix);
			System.out.println("Please selsct [Ascending/Decending](Input [A/S])：");
			String as = input.next();
			if (as.equals("A")) {
				comparator = new HanyuuFileComparator(1);
			} else {
				comparator = new HanyuuFileComparator(0);
			}
			File[] files = file.listFiles(filter);
			System.out.println("File list length:" + Integer.toString(files.length));
			Arrays.sort(files, comparator);
			for (int i = 0; i < files.length; ++i) {
				if (files[i].isFile()) {
					System.out.println((new Date(files[i].lastModified()) + "\t".toString() + files[i].toString()));
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
//		DirFilter filter = new DirFilter(".+log");
		lister.listDirectory(/* new File("c:/Windows"),filter, new AlphabeticComparator() */);
	}
}
