/*
# Dependences:
#   * openjdk-n-jdk
#   * mariadb-server
#   * libmariabd-java

# bash script to create "classpath" (java enironment variable)
if [[ -v CLASSPATH ]]; then
	CLASSPATH="$CLASSPATH:/usr/share/java/mariadb-java-client.jar:/usr/share/java/mariadb-java-client-2.3.0.jar"
else
	export CLASSPATH=".:/usr/share/java/mariadb-java-client.jar:/usr/share/java/mariadb-java-client-2.3.0.jar" >> ~/.bashrc
fi

# after:
source ~/.bashrc
*/

import java.util.Enumeration;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.DriverManager;
import java.sql.Driver;

public class sql_query{

	static String username, password, database;
	static Connection conn;
	static ResultSet res;

	public static void main(String[] args){
		conn = null;

		username = getArg(args, (byte)0, "database user name");
		password = getArg(args, (byte)1, "user password");
		database = getArg(args, (byte)2, "database name");

		connectToDatabase();
		displayEnableDrivers();
		doQuery();
	
		if(conn != null){
			try{
				conn.close();
			}catch(Exception e){
				abort("An error occurred during the closing of connection.");
			}
		}

		System.out.println("Hello world!");
	}

	private static String getArg(String[] args, byte id, String argName){
		try{
			return args[id];
		
		}catch(ArrayIndexOutOfBoundsException e){
			abort("The " + argName + " was not specified.");
			return null;
		}
	}

	private static void connectToDatabase(){
		// it is unnecessary to load mariadb driver;
		// see: https://stackoverflow.com/questions/28220724/class-fornamejdbc-driver-no-longer-needed#28220844
		// try{
		// 	Class.forName("org.mariadb.jdbc.Driver");
		// }catch(ClassNotFoundException e){
		// 	abort("Databank driver not found.");
		// }

		try{
			conn = DriverManager.getConnection("jdbc:mariadb://localhost:3306/" + database, username, password);
		}catch(SQLException e){
			abort("An error occurred during the access to database: " + e.getMessage());
		}
	}

	private static void doQuery(){
		try{
			res = conn.createStatement().executeQuery("SHOW TABLES;");

			System.out.println("Database tables:");

			while(res.next())
				System.out.println(res.getString(1));

		}catch(Exception e){
			abort("An error occurred during the SQL query.");
		}

		System.out.print("\n");
	}

	private static void displayEnableDrivers(){
		Enumeration list = DriverManager.getDrivers();
		Driver curDriver;

		System.out.println("Enable drivers:");

		while(list.hasMoreElements()){
			curDriver = (Driver)list.nextElement();

			System.out.println( curDriver.getClass().getName() );
		}

		System.out.print("\n");
	}

	private static void abort(String msg){
		System.out.println(msg);
		System.exit(1);
	}
}
