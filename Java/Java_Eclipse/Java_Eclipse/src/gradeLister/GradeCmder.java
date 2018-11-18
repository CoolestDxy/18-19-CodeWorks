/**
 * @package gradeLister
 * @filename GradeCmder.java
 * @author Hanyuu
 * @date 2018/53/11
 * @todo TODO
 */
package gradeLister;

import java.io.File;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Map;
import java.util.Scanner;

/**
 * @typename GradeCmder
 * @package gradeLister
 * @description GradeCmder
 * @author Hanyuu
 * @date 2018/11/11
 * @TODO TODO
 */
public class GradeCmder {
//	private ArrayList<Grade> grade;
	/**
	 * String 学号 Grade 结构体
	 */
	private HashMap<String, Grade> gradeMap;
	private GradeInput input;
	private GradeOutput output;
	private File file;
	private NameRandomizer nr;

	GradeCmder() {
//		grade=new ArrayList<Grade>();
		gradeMap = new HashMap<String, Grade>();
		nr = new NameRandomizer();
	}

	public void printGradeBook() {
//		if (grade.isEmpty()) {
//			return;
//		} else {
//			for (Iterator<Grade> iter = grade.iterator(); iter.hasNext();) {
//				Grade temp = iter.next();
//				System.out.println(temp.getID() + "\t" + temp.getName() + "\t" + temp.getGrade());
//			}
//			
//		}
		if (gradeMap.isEmpty()) {
			return;
		}
		Iterator iter = gradeMap.entrySet().iterator();
		System.out.println("ID\tname\t\tgrade");
		System.out.println("===============================");
		while (iter.hasNext()) {
			Map.Entry entry = (Map.Entry) iter.next();
			Grade temp = (Grade) entry.getValue();
			System.out.println(temp.getID() + "\t" + temp.getName() + "\t" + temp.getName());
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
			System.out.println(
					"【1】read grade book from file;\n【2】add record;\n【3】save;\n【4】print grade book;\n【5】randomize product list;\n【6】quit");
			int caseNumber = cmderLine.nextInt();
			switch (caseNumber) {
			// 【1】Read grade book from file
			case 1:
				System.out.println("Input the data file name:");
				file = new File(cmderLine.next());
				try {
					input = new GradeInput(file);
					do {
//						grade.add(input.read());
						gradeMap = (HashMap<String, Grade>) input.read();
						input.release();
					} while (true);

				} catch (Exception exp) {
					System.err.print(exp.getMessage());
				} finally {
					try {
						input.release();
					} catch (Exception exp) {
						;
					}
					System.out.println("file load success.");

				}
//				printGradeBook();
//				System.out.println(grade.size());
				break;

			// 【2】add record
			case 2:
//				cmderLine.close();
//				cmderLine=new Scanner(System.in);
				System.out.println("Input new student's ID:");
				Grade temp = new Grade();
				try {

					temp.setID(cmderLine.next());
					if (gradeMap.containsKey(temp.getID())) {
						System.out.println("The ID already exists.\n add operation failed.");
						break;
					}
					System.out.println("Input student's name:");
					temp.setName(cmderLine.next());
					System.out.println("Input his grade:");
					temp.setGrade(cmderLine.nextInt());
				} catch (Exception exp) {
					System.err.println(exp.getMessage());
				}
//				grade.add(temp);
				gradeMap.put(temp.getID(), temp);
				break;
			// 【3】save
			case 3:
				try {
					output = new GradeOutput(file);
//					for (Iterator<Grade> iter = grade.iterator(); iter.hasNext();) {
//						temp = iter.next();
//						output.write(temp);
//					}
					output.write(gradeMap);
					output.release();
				} catch (Exception exp) {
					System.err.println(exp.getMessage());
				}
				break;
			// [4]print grade book
			case 4:
				printGradeBook();
				break;
			// 【5】:randomize
			case 5:
				String tempID = nr.getRandomID();
				Grade tempGrade=new Grade();
				System.out.println("The number of students you want to generate:");
				int number = cmderLine.nextInt();
				if (number<=0) {
					System.out.println("You can't generate that number of students.");
					break;
				}
				for (int i=0 ;i<number;i++) {
					while (gradeMap.containsKey(tempID)) {
						tempID = nr.getRandomID();
				}
					try {
					tempGrade.setID(tempID);
					tempGrade.setName(nr.getRandomName());
					tempGrade.setGrade(nr.getRandomScore());
					gradeMap.put(tempID, tempGrade);
					}
					catch(Exception e){
						System.err.println("Gererate exception, add filed;");;
					}
				}

				break;
			case 6:
				cmderLine.close();
				return;
			// break;
			}
		}
	}

	/**
	 * @param args
	 * @author Hanyuu
	 * @date 2018/11/11
	 */
	public static void main(String[] args) {
		// System.out.println(System.getProperty("user.dir"));
		GradeCmder cmder = new GradeCmder();
		cmder.cmder();
	}

}
