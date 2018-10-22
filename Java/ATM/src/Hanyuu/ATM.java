package Hanyuu;

import Hanyuu.Account;

import java.util.Scanner;

public class ATM {
	/*
	Status:
		0:尚未登陆
		1:已登录在主界面
		2:存款
		3:取款
		4:退出
	 */
	public static Scanner reader = new Scanner(System.in);
	private int status = 0;
	private Account user;
	ATM(String username,String password){
		user=new Account(username,password);
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
		ATM exp=new ATM(tempUsername,tempPassword);
		while (exp.menuManager());
	}
	public  boolean menuManager (){
		while (status!=5){
			switch (status){
				case 0://尚未登陆
					System.out.println("\n======\nLogin\n======");
					System.out.println("[user name]");
					String tempUserName=ATM.reader.nextLine();
					System.out.println("[password]");
					String tempPassword=ATM.reader.nextLine();
					//login
					if (user.login(tempUserName,tempPassword)){
						status=1;
						System.out.println("[info] login success.");
						break;
					}
					else {
						System.out.println("[error] login failed.");
						break;
					}
				case 1://已登录
					System.out.println("\n======\n Welcome "+user.getUserName()+"\n======");
					System.out.println("menu:\n\t1:Inquiry your balance\n\t2:withdraw\n\t3:deposit\n\t4:exit");
					System.out.println("Choose:");
					int choose=ATM.reader.nextInt();
					while (choose<1 && choose >5){
						System.out.println("invaild input ,input again;\nChoose:");
						choose=ATM.reader.nextInt();
					}
					status=choose;
					break;
				case 2://取款
					System.out.println("Please input how much you withdraw:");
					if (ATM.reader.hasNextDouble()){
						double balance=ATM.reader.nextDouble();
						if(!user.withdraw(balance)){
							System.out.println("[error]value can\'t be negivate");
							status=1;
						};
						//System.out.println("[error] not valued");
					}
					break;
				case 3://存款
					System.out.println("Please input how much you deposit");
					if (ATM.reader.hasNextDouble()){
						double balance=ATM.reader.nextDouble();
						if(!user.deposit(balance)){
							System.out.println("[error]value can\'t be negivate");
							status=1;
						};
						//System.out.println("[error] not valued");
					}
					break;
				case 4://查询
					System.out.println("[balance]"+user.getBalance());
					status=1;
				case 5://退出
					return false;
			}
		}
		//exit the program
		return false;
	}
}
