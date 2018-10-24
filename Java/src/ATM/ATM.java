package ATM;

import java.util.Scanner;

public class ATM {
	/*
	Status:
		-1:尚未登陆
		0:已登录
		1:查询
		2:存款
		3:取款
		4:退出
	 */
	public static Scanner reader = new Scanner(System.in);
	private int status = -1;
	private Account user;

	ATM(String username, String password) {
		user = new Account(username, password);
	}

	public static void main(String[] args) {
		String tempUsername;
		String tempPassword;
		System.out.println("Hi,Please register your account now!");
		System.out.println("\t Input your user name:");
		tempUsername = ATM.reader.nextLine();
		System.out.println("\t Hi " + tempUsername + ". Please input your password here:");
		tempPassword = ATM.reader.nextLine();
		System.out.println("Register success, now you can login with your new account.");
		ATM exp = new ATM(tempUsername, tempPassword);
		while (exp.menuManager()) ;
	}

	public boolean menuManager() {
		while (true) {
			switch (status) {
				case -1://尚未登陆
					System.out.println("\n======\nLogin\n======");
					System.out.println("[user name]");
					String tempUserName = ATM.reader.nextLine();
					System.out.println("[password]");
					String tempPassword = ATM.reader.nextLine();
					//login
					if (user.login(tempUserName, tempPassword)) {
						status = 0;
						System.out.println("[info] login success.");
						break;
					} else {
						System.out.println("[error] login failed.");
						break;
					}
				case 0://已登录
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
				case 1://查询
					System.out.println("[balance]" + user.getBalance());
					status = 0;
					break;
				case 2://取款
					System.out.println("Please input how much you withdraw:");
					if (ATM.reader.hasNextDouble()) {
						double balance = ATM.reader.nextDouble();
						if (!user.withdraw(balance)) {
							System.out.println("[error]value can\'t be negivate");
							status = 0;
						}
						;
						status = 0;
						//System.out.println("[error] not valued");
					}
					break;
				case 3://存款
					System.out.println("Please input how much you deposit");
					if (ATM.reader.hasNextDouble()) {
						double balance = ATM.reader.nextDouble();
						if (!user.deposit(balance)) {
							System.out.println("[error]value can\'t be negivate");
							status = 0;
						}
						status = 0;
						//System.out.println("[error] not valued");
					}
					break;
				case 4://退出
					status = -1;
			}
		}
	}
}
