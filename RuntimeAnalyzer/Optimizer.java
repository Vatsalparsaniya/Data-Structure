package com.wordpress.viscerali.util.timeanalyzer;
/**
 * @author Jagreet Das Gupta
 */
import java.lang.reflect.Method;
import java.util.Scanner;
import java.util.concurrent.TimeUnit;

public class Optimizer implements TimeAnalyzer {
	TimeAnalyzer obj;
	public Optimizer(TimeAnalyzer t){
		this.obj  = t;
	}
	TimeAnalyzer ta = new NanoTimeAnalyzer();
	boolean stopped = false, started = false, optimized = false;
	public void stop() throws TimeAnalyzerException {
		if(optimized){
			obj.stop();
		}
		if(stopped) throw new TimeAnalyzerException(this.toString()+" already stopped");
		ta.resume();
		try{
			obj.stop();
		}finally{
			stopped = true;
			ta.stop();
		}
	}
	public void start() throws TimeAnalyzerException {
		if(optimized){
			obj.start();
		}
		if(started) throw new TimeAnalyzerException(this.toString()+" already started");
		ta.start();
		try{
			obj.start();
		}finally{
			started = true;
			ta.pause();
		}

	}
	public boolean resume() throws TimeAnalyzerException {
		if(optimized){
			return obj.resume();
		}
		if(stopped) throw new TimeAnalyzerException(this.toString()+" has been stopped");
		ta.resume();
		try{
			return obj.resume();
		}finally{ta.pause();}
	}
	public boolean pause() throws TimeAnalyzerException {
		if(optimized){
			return obj.pause();
		}
		if(stopped)	throw new TimeAnalyzerException(this.toString()+" has been stopped");
		ta.resume();
		try{
			return obj.pause();
		}finally{ta.pause();}
	}
	//MOST IMPORTANT METHOD
	public void optimize() throws TimeAnalyzerException{
		if(optimized) throw new TimeAnalyzerException("Already Optimized");
		try{
			Method m = obj.getClass().getMethod("optimized");
			m.invoke(obj);
		}catch(Exception e){}
		if(!stopped){
			ta.stop();
			stopped = true;
		}
		obj.setElapsed((long)obj.elapsed()-(long)ta.elapsed());
		optimized = true;
	}
	public Object elapsed() {
		if(optimized){
			return obj.elapsed();
		}
		ta.resume();
		try{
			return obj.elapsed();
		}finally{ta.pause();}
	}
	public void setElapsed(Object time) {
		if(optimized){
			obj.setElapsed(time);
		}
		ta.resume();
		try{
			obj.setElapsed(time);
		}finally{ta.pause();}
	}
	public String getPausedTime(TimeUnit unit) throws TimeAnalyzerException {
		if(optimized){
			return obj.getPausedTime(unit);
		}
		ta.resume();
		try{
			return obj.getPausedTime(unit);
		}finally{ta.pause();}
	}
	public String getElapsedTime(TimeUnit unit) throws TimeAnalyzerException {
		if(optimized){
			return obj.getElapsedTime(unit);
		}
		ta.resume();
		try{
			return obj.getElapsedTime(unit);
		}finally{ta.pause();}
	}
}
