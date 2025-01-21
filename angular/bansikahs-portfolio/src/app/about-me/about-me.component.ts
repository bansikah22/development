import { Component } from '@angular/core';

@Component({
  selector: 'app-about-me',
  templateUrl: './about-me.component.html',
  styleUrls: ['./about-me.component.css']
})
export class AboutMeComponent {
  // Properties related to the About Me section can be added here
  name: string = "Bansikah";
  title: string = "DevOps Engineer";
  skills: string[] = ["CI/CD", "Cloud Computing", "Containerization", "Automation"];
  
  // Method to get a brief description
  getDescription(): string {
    return `Hello, I'm ${this.name}, a ${this.title} with skills in ${this.skills.join(', ')}.`;
  }
}