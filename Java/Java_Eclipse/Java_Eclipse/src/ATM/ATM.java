package ATM;

import java.util.Scanner;
import java.util.HashMap;

public class ATM {
	/*
	 * Status: -1:尚未登陆 0:已登录 1:查询 2:存款 3:取款 4:退出
	 */
	public static Scanner reader;
	private int status = -1;
	private Account user;
	private HashMap<String, Account> database;

	ATM() {
		reader = new Scanner(System.in);
		database = new HashMap<String, Account>();
	}

	public boolean menuManager() {
		while (true) {
			switch (status) {
//				case -1://尚未登陆
//					System.out.println("\n======\nLogin\n======");
//					System.out.println("[user name]");
//					String tempUserName = ATM.reader.nextLine();
//					System.out.println("[password]");
//					String tempPassword = ATM.reader.nextLine();
//					//login
//					if (user.login(tempUserName, tempPassword)) {
//						status = 0;
//						System.out.println("[info] login success.");
//						break;
//					} else {
//						System.out.println("[error] login failed.");
//						break;
//					}
			case -1:// 尚未登陆
				System.out.println("\n======\nWelcome\n====");
				System.out.println("menu:\n\t1:new Account\n\t2:Login\n");
				int select = 1;
				if (ATM.reader.hasNextInt()) {
					select = ATM.reader.nextInt();
				}
				String tempUsername;
				String tempPassword;
				switch (select) {
				case 1:
					System.out.println("Hi,Please register your account now!");
					System.out.println("\t Input your user name:");
					tempUsername = ATM.reader.next();
					if (!((tempUsername.charAt(0) >= 'A' && tempUsername.charAt(0) <= 'Z')
							|| (tempUsername.charAt(0) >= 'a' && tempUsername.charAt(0) <= 'z'))) {
						System.out.println("用户名必须以字母开头");
						break;
					}
					if (database.get(tempUsername) != null) {
						System.out.println("用户名已被占用");
						break;
					}
					System.out.println("\t Hi " + tempUsername + ". Please input your password here:");
					tempPassword = ATM.reader.next();
					if (tempPassword.length() < 9) {
						System.out.println("密码必须大于8位");
						break;
					}
					System.out.println("Register success, now you can login with your new account.");
					Account temp = new Account(tempUsername, tempPassword);
					database.put(tempUsername, temp);
					break;
				case 2:
					System.out.println("\n======\nLogin\n======");
					System.out.println("[user name]");
					tempUsername = ATM.reader.next();
					System.out.println("[password]");
					tempPassword = ATM.reader.next();
					// login
					if (database.get(tempUsername) != null
							&& database.get(tempUsername).getPassword().equals(MD5Util.MD5(tempPassword))) {
						status = 0;
						System.out.println("[info] login success.");
						user=database.get(tempUsername);
						break;
					} else {
						System.out.println("[error] login failed.");
						break;
					}
				default:
					System.out.println("Invaild input");
					break;
				}

				break;
			case 0:// 已登录
				System.out.println("\n======\n Welcome " + user.getUserName() + "\n======");
				System.out.println("menu:\n\t1:Inquiry your balance\n\t2:withdraw\n\t3:deposit\n\t4:exit");
				System.out.println("Choose:");
				int choose = ATM.reader.nextInt();
				while (choose < 1 && choose > 4) {
					System.out.println("invaild input ,input again;\nChoose:");
					choose = ATM.reader.nextInt();
				}
				status = choose;
				break;
			case 1:// 查询
				System.out.println("[balance]" + user.getBalance());
				status = 0;
				break;
			case 2:// 取款
				System.out.println("Please input how much you withdraw:");
				if (ATM.reader.hasNextDouble()) {
					double balance = ATM.reader.nextDouble();
					if (!user.withdraw(balance)) {
						System.out.println("[error]value can\'t be negivate");
						status = 0;
					}
					;
					status = 0;
					// System.out.println("[error] not valued");
				}
				break;
			case 3:// 存款
				System.out.println("Please input how much you deposit");
				if (ATM.reader.hasNextDouble()) {
					double balance = ATM.reader.nextDouble();
					if (!user.deposit(balance)) {
						System.out.println("[error]value can\'t be negivate");
						status = 0;
					}
					status = 0;
					// System.out.println("[error] not valued");
				}
				break;
			case 4:// 退出
				status = -1;
				break;
			}
		}
	}

	public static void main(String[] args) {
		ATM exp = new ATM();
		exp.menuManager();
	}
}
