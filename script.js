document.getElementById('year').textContent = new Date().getFullYear();

const body = document.body;
const toggle = document.getElementById('navToggle');
const backdrop = document.getElementById('backdrop');
const navLinks = document.querySelectorAll('#sideNav a[data-nav]');

function openNav(){ body.classList.add('nav-open'); toggle.setAttribute('aria-expanded','true'); }
function closeNav(){ body.classList.remove('nav-open'); toggle.setAttribute('aria-expanded','false'); }

toggle.addEventListener('click', () => {
  body.classList.contains('nav-open') ? closeNav() : openNav();
});
backdrop.addEventListener('click', closeNav);
navLinks.forEach(link => link.addEventListener('click', closeNav));
document.addEventListener('keydown', e => { if (e.key === 'Escape') closeNav(); });

// scroll-spy: highlight active section in nav
const sections = document.querySelectorAll('main section[id]');
const spy = new IntersectionObserver((entries) => {
  entries.forEach(entry => {
    const link = document.querySelector(`#sideNav a[href="#${entry.target.id}"]`);
    if (!link) return;
    if (entry.isIntersecting) {
      navLinks.forEach(l => l.classList.remove('active'));
      link.classList.add('active');
    }
  });
}, { rootMargin: '-40% 0px -50% 0px', threshold: 0 });
sections.forEach(s => spy.observe(s));
