/**
 * @package gradeLister
 * @filename GradeCmder.java
 * @author Hanyuu
 * @date 2018/53/11
 * @todo TODO
 */
package gradeLister;

import java.util.HashMap;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;
import java.io.File;
import java.lang.Exception;

/**
 * @typename GradeCmder
 * @package gradeLister
 * @description GradeCmder
 * @author Hanyuu
 * @date 2018/11/11
 * @TODO TODO
 */
public class GradeCmder {
	private ArrayList<Grade> grade;
	private GradeInput input;
	private GradeOutput output;
	private File file;

	GradeCmder()
	{
		grade=new ArrayList<Grade>();
	}
	public void printGradeBook() {
		if (grade.isEmpty()) {
			return;
		} else {
			for (Iterator<Grade> iter = grade.iterator(); iter.hasNext();) {
				Grade temp = iter.next();
				System.out.println(temp.getID() + "\t" + temp.getName() + "\t" + temp.getGrade());
			}
		}
	}

	/**
	 * 
	 * @author Hanyuu
	 * @date 2018/11/11
	 */
	public void cmder() {
		Scanner cmderLine = new Scanner(System.in);
		while (true) {
			System.out
					.println("【1】read grade book from file;\n【2】add record;\n【4】save;\n【4】print grade book;\n【5】quit");
			int caseNumber = cmderLine.nextInt();
			switch (caseNumber) {
			// 【1】Read grade book from file
			case 1:
				System.out.println("Input the data file name:");
				file = new File(cmderLine.nextLine());
				try {
					input = new GradeInput(file);
					output = new GradeOutput(file);
					while (input.hasNext() != 0) {
						grade.add(input.read());
					}
				} catch (Exception exp) {
					System.err.print(exp.getMessage());
				}

				// 【2】add record
			case 2:
//				cmderLine.close();
//				cmderLine=new Scanner(System.in);
				System.out.println("Input new student's ID:");
				Grade temp = new Grade();
				try {

					temp.setID(cmderLine.next());
					System.out.println("Input student's name:");
					temp.setName(cmderLine.next());
					System.out.println("Input his grade:");
					temp.setGrade(cmderLine.nextInt());
				} catch (Exception exp) {
					System.err.println(exp.getMessage());
				}
				grade.add(temp);
				// 【3】save
			case 3:
				for (Iterator<Grade> iter = grade.iterator(); iter.hasNext();) {
					temp = iter.next();
					try {
						output.write(temp);
					} catch (Exception exp) {
						System.err.println(exp.getMessage());
					}

				}
				// [4]print grade book
			case 4:
				printGradeBook();
			case 5:
				cmderLine.close();
				try {
					input.release();
					output.release();
				} catch (Exception exp) {
					System.err.println(exp.getMessage());
				}
				return;
			}
		}
	}

	/**
	 * @param args
	 * @author Hanyuu
	 * @date 2018/11/11
	 */
	public static void main(String[] args) {
		GradeCmder cmder = new GradeCmder();
		cmder.cmder();
	}

}
